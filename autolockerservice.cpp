#include "autolockerservice.h"

AutoLockerService::AutoLockerService(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{
    this->settingsService = settingsService;
    this->logger = logger;
    workThread = new QThread;
}

void AutoLockerService::run()
{
    changeStateService(Run,SERVICE_NAME);
    while (true) {
        qDebug("AutoLockerService");
        _sleep(5000);
    }

}

void AutoLockerService::changeStateServiceSlot(QString service, int state) noexcept
{
    if(service == SERVICE_NAME) changeStateService((ServiceState)state,SERVICE_NAME);
}
