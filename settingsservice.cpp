#include "settingsservice.h"
#include "exception.h"
SettingsService::SettingsService()
{
    Settings = new QSettings("Settings.ini",QSettings::IniFormat);
    if(Settings->value("VERSION","nan").toString() != VERSION) initSettings();
    else loadSettings();
    if(!isValid())
    throw(Exception("InlegalSettingsException"));
}

void SettingsService::initSettings() noexcept
{
    Settings->setValue("VERSION",VERSION);
    Settings->setValue("LogLevel",LogLevel);
    Settings->setValue("Timeout_s",Timeout_s);
    Settings->setValue("Tray",Tray);
    Settings->setValue("delayWorkStansionStateService_s",delayWorkStansionStateService_s);
    //qDebug()<<"init";
}

void SettingsService::loadSettings() noexcept
{
    LogLevel = Settings->value("LogLevel",LogLevel).toInt();
    Timeout_s = Settings->value("Timeout_s",Timeout_s).toInt();
    Tray = Settings->value("Tray",Tray).toBool();
    delayWorkStansionStateService_s = Settings->value("delayWorkStansionStateService_s",delayWorkStansionStateService_s).toInt();
    //qDebug()<<"load";
}

bool SettingsService::isValid() noexcept
{
    if(LogLevel < 0||LogLevel>2) return false;
    if(delayWorkStansionStateService_s > 30) return false;
    return true;
}
