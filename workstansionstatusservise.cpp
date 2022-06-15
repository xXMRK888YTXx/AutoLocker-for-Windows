#include "workstansionstatusservise.h"

WorkStansionStatusServise::WorkStansionStatusServise(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{

}

bool WorkStansionStatusServise::getWorkStansionState() //true - pc is not lock; false - pc is lock;
{
    HDESK desktop = OpenDesktop(TEXT("Default"), 0, false, DESKTOP_SWITCHDESKTOP);
        if (desktop)
        {
            if (SwitchDesktop(desktop))
            {
                CloseDesktop(desktop);
                return true;
            }
            else
            {
                CloseDesktop(desktop);
            }
        }
        else {
            throw Exception("DesktopisNULL");
        }

        return false;
}

void WorkStansionStatusServise::run()
{
   while(true) {
       qDebug()<<getWorkStansionState();
       Sleep(1000);
   }
}
