#include "autolockerservice.h"

AutoLockerService::AutoLockerService(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{
    this->settingsService = settingsService;
    this->logger = logger;
    workThread = new QThread;
}

MousePoint AutoLockerService::getPosMouse()
{
    POINT pos;
    GetCursorPos(&pos);
    if(pos.x > 10000||pos.y > 10000) throw Exception("InlegalMousePosException",logger);
    return MousePoint(pos);
}

void AutoLockerService::run()
{
    workThread->create([&](){
        while (getService_State() == Run) {
            try {
                qDebug()<<getPosMouse().toString();
            } catch (Exception &e) {
                //changeStateService(Stop,SERVICE_NAME);
            }
            _sleep(1000);
        }
    })->start();


}

void AutoLockerService::changeStateServiceSlot(QString service, int state) noexcept
{
    if(service == SERVICE_NAME) changeStateService((ServiceState)state,SERVICE_NAME);
}
