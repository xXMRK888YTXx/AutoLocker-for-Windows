#include "logger.h"
#include "exception.h"
Logger::Logger(SettingsService *settings)
{
    this->settings = nullptr;
    setFilter((logFilter)settings->getLogLevel());
    logFile.setFileName(LOG_FILE_NAME);
    if(filter == NoLog) return;
    if(logFile.open((QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))) {
       log(Log_m,"");
       log(Log_m ,"Programm Started in "+QDateTime::currentDateTime().toString()+" "+settings->VERSION);
    }
    else {
        throw Exception("OpenFileLogException",this);
    }
}

Logger::~Logger()
{
    logFile.close();
}

void Logger::setFilter(logFilter filter) noexcept
{
    this->filter = filter;
}

void Logger::log(Tag tag, QString msg) noexcept
{

     /*потом удалить*/ qDebug()<<msg;
    if((int)tag <= (int)filter&&filter != logFilter::NoLog) {
        QTextStream write(&logFile);
        write<<msg<<endl;
    }
}

