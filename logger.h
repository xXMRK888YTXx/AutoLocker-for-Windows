#ifndef LOGGER_H
#define LOGGER_H

enum logFilter{
    NoLog = 0,
    ErrorsOnly = 1,
    Full = 2
};
enum Tag{
    Errors = 1,
    Info = 2
};
#include <QString>
#include <QDebug>
class Logger
{
public:
    Logger();
    ~Logger();
    void setFilter(logFilter filter) noexcept {this->filter = filter;};
    void log(Tag tag,QString msg);
private:
    logFilter filter = NoLog;
};

#endif // LOGGER_H
