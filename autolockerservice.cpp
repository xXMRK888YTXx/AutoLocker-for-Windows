#include "autolockerservice.h"

AutoLockerService::AutoLockerService(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{

}

void AutoLockerService::run()
{
    while (true) {
        qDebug("AutoLockerService");
        _sleep(1000);
    }
}
