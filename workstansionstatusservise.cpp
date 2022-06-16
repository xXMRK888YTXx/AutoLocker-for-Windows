#include "workstansionstatusservise.h"

WorkStansionStatusServise::WorkStansionStatusServise(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{
    this->settingsService = settingsService;
    this->logger = logger;
    workThread = new QThread;
    delay = settingsService->getDelayWorkStansionStateService() * 1000;

}

bool WorkStansionStatusServise::getWorkStansionState() //true - pc is not lock; false - pc is lock;
{
    HDESK desktop = OpenDesktop(TEXT("Default"), 0, false, DESKTOP_SWITCHDESKTOP);
        if (desktop) {
            if (SwitchDesktop(desktop)) {
                CloseDesktop(desktop);
                return true;
            }
            else {
                CloseDesktop(desktop);
            }
        }
        else {
            throw Exception("DesktopisNULL");
        }
        return false;
}

void WorkStansionStatusServise::stateWorkStansionChanged()
{
    stateWorkStansion = !stateWorkStansion;
    emit workStansionStateChangedSignal(stateWorkStansion);
}

void WorkStansionStatusServise::run()
{
    stateWorkStansion = getWorkStansionState();
    workThread->create([&](){
        while(service_State == Run) {
           if(stateWorkStansion != getWorkStansionState())
               stateWorkStansionChanged();
           Sleep(delay);
        }
        qDebug()<<"qwe";
    })->start();
}

void WorkStansionStatusServise::changeStateServiceSlot(QString service, int state) noexcept
{
    if(service == SERVICE_NAME) changeStateService((ServiceState)state,SERVICE_NAME);
}

