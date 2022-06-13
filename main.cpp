#include <QCoreApplication>
#include "settingsservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SettingsService s;
    return a.exec();
}
