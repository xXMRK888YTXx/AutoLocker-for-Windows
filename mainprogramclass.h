#ifndef MAINPROGRAMCLASS_H
#define MAINPROGRAMCLASS_H

#include <QObject>
#include <QThread>
#include "logger.h"
#include "settingsservice.h"
#include <windows.h>
#include "autolockerservice.h"
#include "workstansionstatusservise.h"
class MainProgramClass : public QObject
{
    Q_OBJECT
public:
    explicit MainProgramClass(Logger *logger, SettingsService *settingsService, QObject *parent = nullptr);
private:
    bool workStansionState = true;
    QThread *autoLockerThread;
    QThread *workStansionStatusThread;
    QThread *hotKeyCheckerThread;
    WorkStansionStatusServise *workStansionStatusServise;
    AutoLockerService *autoLockerService;
    SettingsService *settingsService;
    void trackHotKey();
    Logger *logger;
    void globalStateChange(ServiceState state);
signals:
    void changeServiseState(QString service,int state);
private slots:
    void workStansionStateChangedSlot(bool state);
};

#endif // MAINPROGRAMCLASS_H
