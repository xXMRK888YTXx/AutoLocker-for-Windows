#ifndef LOGGER_H
#define LOGGER_H

enum logFilter{
    NoLog = 0,
    ErrorsOnly = 1,
    Full = 2
};
enum Tag{
    Log_m = 0,
    Errors = 1,
    Info = 2
};
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QMutex>
#include "settingsservice.h"
class Logger
{
public:
    Logger(SettingsService *settings);
    ~Logger() noexcept;
    void setFilter(logFilter filter) noexcept;
    void log(Tag tag,QString msg) noexcept;
    QFile logFile;
    QMutex mutex;
    SettingsService *settings = nullptr;
private:
    logFilter filter = NoLog;
    const QString LOG_FILE_NAME = "log.txt";
};

#endif // LOGGER_H
