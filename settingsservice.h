#ifndef SETTINGSSERVICE_H
#define SETTINGSSERVICE_H

#include <QSettings>
#include <QDebug>
class SettingsService
{
public:
    SettingsService();
    int getLogLevel() noexcept {return LogLevel;};
    int getTimeout_s() noexcept {return Timeout_s;};
    bool getTray() noexcept {return Tray;};
    short getDelayWorkStansionStateService() noexcept {return delayWorkStansionStateService_s;};
    const QString VERSION = "1.0alpha";
private:
    QSettings *Settings;
    int LogLevel = 0;
    int Timeout_s = 60;
    short delayWorkStansionStateService_s = 2;
    bool Tray = false;
    void initSettings() noexcept;
    void loadSettings() noexcept;
    bool isValid() noexcept;
};

#endif // SETTINGSSERVICE_H
