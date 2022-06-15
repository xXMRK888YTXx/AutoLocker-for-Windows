#include "exception.h"

Exception::Exception(QString ex)
{
    what(ex);
}


void Exception::what(QString ex)
{
    qDebug()<<"An exception was thrown during program execution --> "+ex<<endl;
}
