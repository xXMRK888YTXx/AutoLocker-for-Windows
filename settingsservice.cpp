#include "settingsservice.h"

SettingsService::SettingsService() noexcept
{
    Settings = new QSettings("Settings.ini",QSettings::IniFormat);
    if(Settings->value("VERSION","nan").toString() != VERSION) initSettings();
    else loadSettings();
}

void SettingsService::initSettings() noexcept
{
    Settings->setValue("VERSION",VERSION);
    Settings->setValue("LogLevel",LogLevel);
    Settings->setValue("Timeout_s",Timeout_s);
    Settings->setValue("Tray",Tray);
    qDebug()<<"init";
}

void SettingsService::loadSettings() noexcept
{
    LogLevel = Settings->value("LogLevel",LogLevel).toInt();
    Timeout_s = Settings->value("Timeout_s",Timeout_s).toInt();
    Tray = Settings->value("Tray",Tray).toBool();
    qDebug()<<"load";
    qDebug()<<Tray;
}
