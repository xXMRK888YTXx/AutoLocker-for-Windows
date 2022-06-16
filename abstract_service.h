#ifndef ABSTRACT_SERVICE_H
#define ABSTRACT_SERVICE_H


#include <QObject>
#include <windows.h>
#include <QDebug>
#include "settingsservice.h"
#include "logger.h"
#include "exception.h"
enum ServiceState{
    Stop = 0,
    Pause = 1,
    Run = 2
};

class Abstract_Service : public QObject
{
    Q_OBJECT
public:
    explicit Abstract_Service(QObject *parent = nullptr);
protected:
    SettingsService *settingsService;
    Logger *logger;
    ServiceState state = Stop;
    void changeState(ServiceState state,QString SERVICE_NAME);
protected slots:
    virtual void run();
};

#endif // ABSTRACT_SERVICE_H
