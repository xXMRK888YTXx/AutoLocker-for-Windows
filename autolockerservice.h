#ifndef AUTOLOCKERSERVICE_H
#define AUTOLOCKERSERVICE_H

#include <QObject>
#include "abstract_service.h"
class AutoLockerService : public Abstract_Service
{
    Q_OBJECT
public:
    explicit AutoLockerService(SettingsService *settingsService,Logger *logger,QObject *parent = nullptr);
signals:

public slots:
    void run() override;

};

#endif // AUTOLOCKERSERVICE_H
