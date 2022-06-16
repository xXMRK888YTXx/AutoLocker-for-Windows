#ifndef AUTOLOCKERSERVICE_H
#define AUTOLOCKERSERVICE_H

#include <QObject>
#include "abstract_service.h"
class AutoLockerService : public Abstract_Service
{
    Q_OBJECT
public:
    explicit AutoLockerService(SettingsService *settingsService,Logger *logger,QObject *parent = nullptr);
    const QString SERVICE_NAME = "AutoLockerService";
signals:
private:
public slots:
    void run() override;
    void changeStateServiceSlot(QString service, int state) noexcept override;

};

#endif // AUTOLOCKERSERVICE_H
