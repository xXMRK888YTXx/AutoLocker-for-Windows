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
class Logger
{
public:
    Logger();
    ~Logger();
    void setFilter(logFilter filter) noexcept;
    void log(Tag tag,QString msg);
    QFile logFile;
private:
    logFilter filter = NoLog;
    const QString LOG_FILE_NAME = "log.txt";
};

#endif // LOGGER_H
