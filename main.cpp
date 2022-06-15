#include <QCoreApplication>
#include "settingsservice.h"
#include "mainprogramclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Logger *l = new Logger();
    SettingsService *s = new SettingsService(l);
    MainProgramClass *m = new MainProgramClass(l,s);
    return a.exec();
}
