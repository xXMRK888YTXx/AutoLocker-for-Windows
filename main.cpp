#include <QCoreApplication>
#include "settingsservice.h"
#include "mainprogramclass.h"
#include <QDebug>
#include <QTimer>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SettingsService *s = new SettingsService();
    Logger *l = new Logger(s);
    MainProgramClass *m = new MainProgramClass(l,s);
    return a.exec();
}
