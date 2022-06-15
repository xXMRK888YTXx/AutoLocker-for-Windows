#include "mainprogramclass.h"

MainProgramClass::MainProgramClass(Logger *logger, SettingsService *settingsService, QObject *parent) : QObject(parent)
{
    autoLockerService = new AutoLockerService(settingsService,logger);
    workStansionStatusServise = new WorkStansionStatusServise(settingsService,logger);
    autoLockerThread = new QThread();
    workStansionStatusThread = new QThread();

    autoLockerService->moveToThread(autoLockerThread);
    workStansionStatusServise->moveToThread(workStansionStatusThread);
    connect(autoLockerThread,SIGNAL(started()),autoLockerService,SLOT(run()));
    connect(workStansionStatusThread,SIGNAL(started()),workStansionStatusServise,SLOT(run()));
    autoLockerThread->start();
    workStansionStatusThread->start();
//    autoLockerService.run();
//    workStansionStatusServise.run();
}
