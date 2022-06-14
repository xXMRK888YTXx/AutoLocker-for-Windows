#include <QCoreApplication>
#include "settingsservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Logger *l = new Logger();
    SettingsService *s = new SettingsService(l);
    return a.exec();
}
