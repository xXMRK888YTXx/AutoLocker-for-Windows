#include "abstract_service.h"

Abstract_Service::Abstract_Service(QObject *parent) : QObject(parent)
{

}

void Abstract_Service::changeStateService(ServiceState state,QString SERVICE_NAME)
{
    if(service_State == state) return;
    service_State = state;
    switch (state) {
    case Stop: {
        logger->log(Info,SERVICE_NAME+" has been stopped");
        break;
    }
    case Run: {
        logger->log(Info,SERVICE_NAME+" has been running");
        run();
        break;
    }
    default: {
        throw Exception("InvalidStateServiceException",logger);
        break;
    }
    }
}

void Abstract_Service::run()
{

}

void Abstract_Service::changeStateServiceSlot(QString service, int state) noexcept
{

}

