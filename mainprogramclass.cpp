#include "mainprogramclass.h"

MainProgramClass::MainProgramClass(Logger *logger, SettingsService *settingsService, QObject *parent) : QObject(parent)
{
    autoLockerService = new AutoLockerService(settingsService,logger);
    workStansionStatusServise = new WorkStansionStatusServise(settingsService,logger);
    autoLockerThread = new QThread();
    workStansionStatusThread = new QThread();
    hotKeyCheckerThread = new QThread();
    this->logger = logger;
    this->settingsService = settingsService;
    autoLockerService->moveToThread(autoLockerThread);
    workStansionStatusServise->moveToThread(workStansionStatusThread);
    connect(workStansionStatusServise,SIGNAL(workStansionStateChangedSignal(bool)),this,SLOT(workStansionStateChangedSlot(bool)));
    connect(this,SIGNAL(changeServiseState(QString,int)),autoLockerService,SLOT(changeStateServiceSlot(QString,int)));
    connect(this,SIGNAL(changeServiseState(QString,int)),workStansionStatusServise,SLOT(changeStateServiceSlot(QString,int)));
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
            if(GetAsyncKeyState(VK_CONTROL)&&GetAsyncKeyState(VK_LSHIFT)&&GetAsyncKeyState('S')) {
                if(workStansionStatusServise->getService_State() == Run)
                    globalStateChange(Stop);
                else if(workStansionStatusServise->getService_State() == Stop)
                    globalStateChange(Run);
                logger->log(Tag::Info,"HotKey");
            }
            Sleep(500);
        }
    })->start();
}

void MainProgramClass::globalStateChange(ServiceState state)
{
    emit changeServiseState(workStansionStatusServise->SERVICE_NAME,(int)state);
    emit changeServiseState(autoLockerService->SERVICE_NAME,(int)state);
}

void MainProgramClass::workStansionStateChangedSlot(bool state)
{
    logger->log(Tag::Info,"Workstansion status changed");
    if(state&&autoLockerService->getService_State() != Run) emit changeServiseState(autoLockerService->SERVICE_NAME,(int)Run);
    else if(!state&&autoLockerService->getService_State() != Stop)  emit changeServiseState(autoLockerService->SERVICE_NAME,(int)Stop);
}
