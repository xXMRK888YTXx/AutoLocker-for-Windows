#include "settingsservice.h"
#include "exception.h"
SettingsService::SettingsService()
{
    Settings = new QSettings("Settings.ini",QSettings::IniFormat);
    if(Settings->value("VERSION","nan").toString() != CURRENT_VERSION) initSettings();
    else loadSettings();
    if(!isValid()) {
         MessageBoxA(NULL, "InlegalSettingsException", "Error", MB_OK);
         throw(Exception("InlegalSettingsException"));
    }
}

void SettingsService::initSettings() noexcept
{
    Settings->setValue(VERSION,CURRENT_VERSION);
    Settings->setValue(LOGLEVEL,LogLevel);
    Settings->setValue(IDLETIMEOUT_S,idleTimeout_s);
    Settings->setValue(DELAYPCSTATECHECK,delayPcStateCheck);
    Settings->setValue(TASK_PROCESS_ENABLE,TaskProcessEnable);
    Settings->setValue(CLOSEPROCESS,closeProcessList);
    //qDebug()<<"init";
}

void SettingsService::loadSettings() noexcept
{
    LogLevel = Settings->value(LOGLEVEL,LogLevel).toInt();
    idleTimeout_s = Settings->value(IDLETIMEOUT_S,idleTimeout_s).toInt();
    delayPcStateCheck = Settings->value(DELAYPCSTATECHECK,delayPcStateCheck).toInt();
    closeProcessList = Settings->value(CLOSEPROCESS).toStringList();
    TaskProcessEnable = Settings->value(TASK_PROCESS_ENABLE,TaskProcessEnable).toBool();
    //qDebug()<<"load";
}

bool SettingsService::isValid() noexcept
{
    if(LogLevel < 0||LogLevel>2) return false;
    if(delayPcStateCheck > 30||delayPcStateCheck < 1) return false;
    if(idleTimeout_s < 10) return false;
    return true;
}

