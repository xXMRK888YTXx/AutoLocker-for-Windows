#ifndef SETTINGSSERVICE_H
#define SETTINGSSERVICE_H

#include <QSettings>
#include <QDebug>
class SettingsService
{
public:
    SettingsService() noexcept;
private:
    QSettings *Settings;
    int LogLevel = 0;
    int Timeout_s = 60;
    bool Tray = false;
    void initSettings() noexcept;
    void loadSettings() noexcept;
    const QString VERSION = "1.0alpha";
};

#endif // SETTINGSSERVICE_H
