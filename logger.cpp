#include "logger.h"
#include "exception.h"
Logger::Logger()
{
    logFile.setFileName(LOG_FILE_NAME);
    if(logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
       log(Tag::Log_m ,"Programm Started in "+QDateTime::currentDateTime().toString());
    }
    else {
        throw Exception("OpenFileLogException",this);
    }
    throw Exception("test",this);
}

Logger::~Logger()
{
    logFile.close();
}

void Logger::setFilter(logFilter filter) noexcept
{
    this->filter = filter;
}

void Logger::log(Tag tag, QString msg)
{
    qDebug()<<filter;
    if((int)tag <= (int)filter&&filter != logFilter::NoLog) {
        QTextStream write(&logFile);
        write<<msg<<endl;
    }
}

