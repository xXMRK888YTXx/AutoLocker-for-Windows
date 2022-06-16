#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <QDebug>
#include "logger.h"

class Exception
{
public:
    Exception(QString ex,Logger *log = nullptr) noexcept;
    void what(QString ex,Logger *log = nullptr) noexcept;    
private:
    const QString DEFAULT_TEXT_EXCEPTION = "An exception was thrown during program execution --> ";
};

#endif // EXCEPTION_H
