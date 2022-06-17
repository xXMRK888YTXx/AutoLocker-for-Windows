#ifndef AUTOLOCKERSERVICE_H
#define AUTOLOCKERSERVICE_H

#include <QObject>
#include "abstract_service.h"
#include "mousepoint.h"
class AutoLockerService : public Abstract_Service
{
    Q_OBJECT
public:
    explicit AutoLockerService(SettingsService *settingsService,Logger *logger,QObject *parent = nullptr);
    const QString SERVICE_NAME = "AutoLockerService";
private:
    MousePoint getPosMouse();
signals:
private slots:
    void run() override;
public slots:
    void changeStateServiceSlot(QString service, int state) noexcept override;

};

#endif // AUTOLOCKERSERVICE_H
