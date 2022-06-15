#ifndef WORKSTANSIONSTATUSSERVISE_H
#define WORKSTANSIONSTATUSSERVISE_H

#include <QObject>
#include "abstract_service.h"
class WorkStansionStatusServise : public Abstract_Service
{
    Q_OBJECT
public:
    explicit WorkStansionStatusServise(SettingsService *settingsService, Logger *logger, QObject *parent = nullptr);
    bool getWorkStansionState();
signals:

public slots:
    void run() override;
};

#endif // WORKSTANSIONSTATUSSERVISE_H
