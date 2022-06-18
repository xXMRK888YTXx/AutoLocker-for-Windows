#include "exception.h"

Exception::Exception(QString ex, Logger *log) noexcept
{
    what(ex,log);
}

void Exception::what(QString ex, Logger *log) noexcept
{
    if(log != nullptr) log->log(Tag::Errors,DEFAULT_TEXT_EXCEPTION+ex);
}
