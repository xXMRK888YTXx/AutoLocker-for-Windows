#include "settingsservice.h"
#include "exception.h"
SettingsService::SettingsService(Logger *logger)
{
    this->logger = logger;
    Settings = new QSettings("Settings.ini",QSettings::IniFormat);
    if(Settings->value("VERSION","nan").toString() != VERSION) initSettings();
    else loadSettings();
    logger->setFilter(GetLogLevel());
    if(!isValid())
    throw(Exception("InlegalSettingsException",logger));
}

void SettingsService::initSettings() noexcept
{
    Settings->setValue("VERSION",VERSION);
    Settings->setValue("LogLevel",LogLevel);
    Settings->setValue("Timeout_s",Timeout_s);
    Settings->setValue("Tray",Tray);
    //qDebug()<<"init";
}

void SettingsService::loadSettings() noexcept
{
    LogLevel = Settings->value("LogLevel",LogLevel).toInt();
    Timeout_s = Settings->value("Timeout_s",Timeout_s).toInt();
    Tray = Settings->value("Tray",Tray).toBool();
    //qDebug()<<"load";
}

bool SettingsService::isValid() noexcept
{
    if(LogLevel < 0||LogLevel>2) return false;

    return true;
}
