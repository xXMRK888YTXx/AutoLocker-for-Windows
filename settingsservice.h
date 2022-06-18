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
    bool getTaskProcessEnable() noexcept {return TaskProcessEnable;};
    QStringList getCloseProcessList() noexcept {return closeProcessList;};
    const QString CURRENT_VERSION = "v1.0beta";
private:
    QSettings *Settings;
    int LogLevel = 0;
    int idleTimeout_s = 120;
    short delayPcStateCheck = 2;
    bool TaskProcessEnable = false;
    QStringList closeProcessList{""};
    void initSettings() noexcept;
    void loadSettings() noexcept;
    bool isValid() noexcept;

    //Keys for settings
    const QString VERSION = "VERSION";
    const QString LOGLEVEL = "LOGLEVEL";
    const QString IDLETIMEOUT_S = "IDLE_TIMEOUT_S";
    const QString DELAYPCSTATECHECK = "DELAY_PC_STATE_CHECK";
    const QString CLOSEPROCESS = "CLOSE_PROCESS";
    const QString TASK_PROCESS_ENABLE = "TASK_PROCESS_ENABLE";
};

#endif // SETTINGSSERVICE_H
