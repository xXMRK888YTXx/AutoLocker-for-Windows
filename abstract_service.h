#ifndef ABSTRACT_SERVICE_H
#define ABSTRACT_SERVICE_H


#include <QObject>
#include <windows.h>
#include <QDebug>
#include "settingsservice.h"
#include "logger.h"
#include "exception.h"
#include <QThread>
#include <QTimer>
enum ServiceState{
    Stop = 0,
    Run = 1
};

class Abstract_Service : public QObject
{
    Q_OBJECT
public:
    explicit Abstract_Service(QObject *parent = nullptr);
    ServiceState getService_State() noexcept {return service_State;};
private:

protected:
    SettingsService *settingsService;
    Logger *logger;
    ServiceState service_State = Stop;
    virtual void changeStateService(ServiceState state,QString SERVICE_NAME);
    QThread *workThread;
protected slots:
    virtual void run();
    virtual void changeStateServiceSlot(QString service,int state) noexcept;
};

#endif // ABSTRACT_SERVICE_H
