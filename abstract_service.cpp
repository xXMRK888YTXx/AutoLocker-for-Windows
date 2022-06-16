#include "abstract_service.h"

Abstract_Service::Abstract_Service(QObject *parent) : QObject(parent)
{

}

void Abstract_Service::changeState(ServiceState state,QString SERVICE_NAME)
{
    this->state = state;
    switch (state) {
    case Stop: {
        logger->log(Info,SERVICE_NAME+"has been stopped");
        break;
    }
    case Pause: {
        logger->log(Info,SERVICE_NAME+"has been paused");
        break;
    }
    case Run: {
        logger->log(Info,SERVICE_NAME+"has been running");
        break;
    }
    default: {
        throw Exception("InvalidStateServiceException",logger);
    }
    }
}

void Abstract_Service::run()
{

}
