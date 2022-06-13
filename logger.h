#ifndef LOGGER_H
#define LOGGER_H

enum LogType{
    NoLog = 0,
    ErrorsOnly = 1,
    Full = 2
};

class Logger
{
public:
    Logger();
};

#endif // LOGGER_H
