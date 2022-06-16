#include "autolockerservice.h"

AutoLockerService::AutoLockerService(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{
    this->settingsService = settingsService;
    this->logger = logger;
}

void AutoLockerService::run()
{
    changeState(Run,SERVICE_NAME);
    while (true) {
        qDebug("AutoLockerService");
        _sleep(1000);
    }

}
