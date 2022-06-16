#include "workstansionstatusservise.h"

WorkStansionStatusServise::WorkStansionStatusServise(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{
    this->settingsService = settingsService;
    this->logger = logger;

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

void WorkStansionStatusServise::stateChanged()
{
    state = !state;
    emit workStansionStateChangedSignal(state);
}

void WorkStansionStatusServise::run()
{
    changeState(Run,SERVICE_NAME);
    while(true) {
       qDebug()<<getWorkStansionState();
       Sleep(1000);
    }
}
