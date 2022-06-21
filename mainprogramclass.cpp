#include "mainprogramclass.h"

MainProgramClass::MainProgramClass(Logger *logger, SettingsService *settingsService, QObject *parent) : QObject(parent)
{
    autoLockerService = new AutoLockerService(settingsService,logger);
    workStansionStatusServise = new WorkStansionStatusServise(settingsService,logger);
    runProcessThread = new QThread;
    closeProcessThread = new QThread;
    autoLockerThread = new QThread;
    workStansionStatusThread = new QThread;
    hotKeyCheckerThread = new QThread;
    this->logger = logger;
    this->settingsService = settingsService;
    autoLockerService->moveToThread(autoLockerThread);
    workStansionStatusServise->moveToThread(workStansionStatusThread);
    connect(workStansionStatusServise,SIGNAL(workStansionStateChangedSignal(bool)),this,SLOT(workStansionStateChangedSlot(bool)));
    connect(this,SIGNAL(changeServiseState(QString,int)),autoLockerService,SLOT(changeStateServiceSlot(QString,int)));
    connect(this,SIGNAL(changeServiseState(QString,int)),workStansionStatusServise,SLOT(changeStateServiceSlot(QString,int)));
    connect(autoLockerService,SIGNAL(pcInIdleMode()),this,SLOT(pcInIdleModeSlot()));
    autoLockerThread->start();
    workStansionStatusThread->start();
    emit changeServiseState(workStansionStatusServise->SERVICE_NAME,(int)Run);
    emit changeServiseState(autoLockerService->SERVICE_NAME,(int)Run);
    trackHotKey();
}

void MainProgramClass::trackHotKey()
{
    hotKeyCheckerThread->create([&](){
        while(true) {
            if(GetAsyncKeyState(VK_RSHIFT)&&GetAsyncKeyState('O')&&GetAsyncKeyState('I')) {
                if(workStansionStatusServise->getService_State() == Run)
                    globalStateChange(Stop,true);
                else if(workStansionStatusServise->getService_State() == Stop)
                    globalStateChange(Run,true);
                logger->log(Tag::Info,"Hotkey pressed");
            }
            Sleep(100);
        }
    })->start();
}

void MainProgramClass::globalStateChange(ServiceState state,bool messagebox)
{
    emit changeServiseState(workStansionStatusServise->SERVICE_NAME,(int)state);
    emit changeServiseState(autoLockerService->SERVICE_NAME,(int)state);
    if(state == Run&&messagebox) {
         MessageBoxA(NULL, "AutoLocker servise is running", "AutoLocker state", MB_OK);

    }
    else if(state == Stop&&messagebox) {
        MessageBoxA(NULL, "AutoLocker servise is stopped", "AutoLocker state", MB_OK);
    }
}

void MainProgramClass::closeProcessTask()
{
    if(!settingsService->getTaskProcessEnable()) return;
    closeProcessThread->create([&](){
        auto list = settingsService->getCloseProcessList();
         QProcess *process = new QProcess;
        for(int i = 0;i<list.size();i++) {
            process->start("taskkill /IM "+list[i]+" /F");
            process->waitForFinished(10000);
            process->close();
            logger->log(Info,list[i]+" terminated");
        }
        delete process;
    })->start();
}

void MainProgramClass::workStansionStateChangedSlot(bool state)
{
    logger->log(Tag::Info,"Workstansion status changed");
    if(state&&autoLockerService->getService_State() != Run) emit changeServiseState(autoLockerService->SERVICE_NAME,(int)Run);
    else if(!state&&autoLockerService->getService_State() != Stop)  emit changeServiseState(autoLockerService->SERVICE_NAME,(int)Stop);
}

void MainProgramClass::pcInIdleModeSlot()
{
    closeProcessTask();
}
