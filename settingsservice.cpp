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
    Settings->setValue("idleTimeout_s",idleTimeout_s);
    Settings->setValue("delayPcStateCheck",delayPcStateCheck);
    //qDebug()<<"init";
}

void SettingsService::loadSettings() noexcept
{
    LogLevel = Settings->value("LogLevel",LogLevel).toInt();
    idleTimeout_s = Settings->value("idleTimeout_s",idleTimeout_s).toInt();
    delayPcStateCheck = Settings->value("delayPcStateCheck",delayPcStateCheck).toInt();
    //qDebug()<<"load";
}

bool SettingsService::isValid() noexcept
{
    if(LogLevel < 0||LogLevel>2) return false;
    if(delayPcStateCheck > 30||delayPcStateCheck < 1) return false;
    if(idleTimeout_s < 10) return false;
    return true;
}
