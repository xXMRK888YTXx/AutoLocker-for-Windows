#ifndef SETTINGSSERVICE_H
#define SETTINGSSERVICE_H

#include <QSettings>
#include <QDebug>
class SettingsService
{
public:
    SettingsService();
    int getLogLevel() noexcept {return LogLevel;};
    int getTimeout_s() noexcept {return idleTimeout_s;};
    short getDelayPcStateCheck() noexcept {return delayPcStateCheck;};
    const QString VERSION = "v1.2alpha";
private:
    QSettings *Settings;
    int LogLevel = 0;
    int idleTimeout_s = 120;
    short delayPcStateCheck = 2;
    void initSettings() noexcept;
    void loadSettings() noexcept;
    bool isValid() noexcept;
};

#endif // SETTINGSSERVICE_H
