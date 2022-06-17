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
    const QString SERVICE_NAME = "WorkStansionStatusServise";
signals:
    void workStansionStateChangedSignal(bool state);
private:
    bool stateWorkStansion;
    void stateWorkStansionChanged();
    short delay;
private slots:
    void run() override;
public slots:
    void changeStateServiceSlot(QString service, int state) noexcept override;
};

#endif // WORKSTANSIONSTATUSSERVISE_H
