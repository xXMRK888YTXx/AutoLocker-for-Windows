#ifndef MAINPROGRAMCLASS_H
#define MAINPROGRAMCLASS_H

#include <QObject>
#include <QThread>
#include "logger.h"
#include "settingsservice.h"
#include "autolockerservice.h"
#include "workstansionstatusservise.h"
class MainProgramClass : public QObject
{
    Q_OBJECT
public:
    explicit MainProgramClass(Logger *logger,SettingsService *settingsService,QObject *parent = nullptr);
private:
    bool workStansionState = true;
    QThread *autoLockerThread;
    QThread *workStansionStatusThread;
    WorkStansionStatusServise *workStansionStatusServise;
    AutoLockerService *autoLockerService;
signals:


};

#endif // MAINPROGRAMCLASS_H
