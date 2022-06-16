#include "mainprogramclass.h"

MainProgramClass::MainProgramClass(Logger *logger, SettingsService *settingsService, QObject *parent) : QObject(parent)
{
    autoLockerService = new AutoLockerService(settingsService,logger);
    workStansionStatusServise = new WorkStansionStatusServise(settingsService,logger);
    autoLockerThread = new QThread();
    workStansionStatusThread = new QThread();

    autoLockerService->moveToThread(autoLockerThread);
    workStansionStatusServise->moveToThread(workStansionStatusThread);
    connect(workStansionStatusServise,SIGNAL(workStansionStateChangedSignal(bool)),this,SLOT(workStansionStateChangedSlot(bool)));
    connect(this,SIGNAL(changeServiseState(QString,int)),autoLockerService,SLOT(changeStateServiceSlot(QString,int)));
    connect(this,SIGNAL(changeServiseState(QString,int)),workStansionStatusServise,SLOT(changeStateServiceSlot(QString,int)));
    autoLockerThread->start();
    workStansionStatusThread->start();
    emit changeServiseState(workStansionStatusServise->SERVICE_NAME,(int)Run);
    Sleep(10000);
    emit changeServiseState(workStansionStatusServise->SERVICE_NAME,(int)Stop);
     Sleep(10000);
    emit changeServiseState(workStansionStatusServise->SERVICE_NAME,(int)Run);
}

void MainProgramClass::workStansionStateChangedSlot(bool state)
{
    qDebug()<<"WorkStansion state change "<<state;
}
