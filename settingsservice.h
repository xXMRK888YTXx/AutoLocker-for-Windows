#ifndef SETTINGSSERVICE_H
#define SETTINGSSERVICE_H

#include <QSettings>
#include <QDebug>
#include "logger.h"
#include <exception.h>
class SettingsService
{
public:
    SettingsService(Logger *logger);
    int GetLogLevel() noexcept {return LogLevel;};
    int GetTimeout_s() noexcept {return Timeout_s;};
    bool GetTray() noexcept {return Tray;};
    QString GetVERSION() noexcept {return VERSION;};
private:
    QSettings *Settings;
    int LogLevel = 0;
    int Timeout_s = 60;
    bool Tray = false;
    void initSettings() noexcept;
    void loadSettings() noexcept;
    const QString VERSION = "1.0alpha";
    bool isValid() noexcept;
    Logger *logger = nullptr;
};

#endif // SETTINGSSERVICE_H
