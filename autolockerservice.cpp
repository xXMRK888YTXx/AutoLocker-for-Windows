#include "autolockerservice.h"

AutoLockerService::AutoLockerService(SettingsService *settingsService, Logger *logger, QObject *parent) : Abstract_Service(parent)
{
    idleTime_ms = 10*1000;
    this->settingsService = settingsService;
    this->logger = logger;
    workThread = new QThread;
    idleTimer = new QTimer(this);
    connect(idleTimer,SIGNAL(timeout()),this,SLOT(pcInIdleStatusSlot()));
    connect(this,SIGNAL(startT(int)),this,SLOT(startTimer(int)));
    connect(this,SIGNAL(resetT()),this,SLOT(resetTimer()));
    connect(this,SIGNAL(stopT()),this,SLOT(stopTimer()));
    idleTimer->stop();
}

MousePoint AutoLockerService::getPosMouse()
{
    POINT pos;
    GetCursorPos(&pos);
    if(pos.x > 10000||pos.y > 10000) throw Exception("InlegalMousePosException");
    return MousePoint(pos);
}

void AutoLockerService::changeStateService(ServiceState state, QString SERVICE_NAME)
{
    Abstract_Service::changeStateService(state,SERVICE_NAME);
    if(state == Stop) {
        emit stopT();
    }
}

void AutoLockerService::resetTimer()
{
    if(!idleTimer->isActive()) return;
    idleTimer->stop();
    idleTimer->start(idleTime_ms);
}

void AutoLockerService::stopTimer()
{
    idleTimer->stop();
}

void AutoLockerService::run()
{
    workThread->create([&](){
        MousePoint currentPos = getPosMouse();
        emit startT(idleTime_ms);
        while (getService_State() == Run) {
            try {
                MousePoint temp = getPosMouse();
                qDebug()<<temp.toString();
                if(currentPos != temp) {
                    currentPos = temp;
                    qDebug()<<"Timer reset";
                    emit resetT();
                }
            } catch (Exception &e) {
                changeStateService(Stop,SERVICE_NAME);
            }
            _sleep(1000);
        }
        emit stopT();
    })->start();
}

void AutoLockerService::pcInIdleStatusSlot()
{
    qDebug()<<"timeout";
    LockWorkStation();
}

void AutoLockerService::startTimer(int s)
{
    idleTimer->start(s);
}

void AutoLockerService::changeStateServiceSlot(QString service, int state) noexcept
{
    if(service == SERVICE_NAME) changeStateService((ServiceState)state,SERVICE_NAME);
}
