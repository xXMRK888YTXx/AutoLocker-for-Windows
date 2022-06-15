#ifndef ABSTRACT_SERVICE_H
#define ABSTRACT_SERVICE_H

#include <QObject>
#include <windows.h>
#include <QDebug>
#include "settingsservice.h"
#include "logger.h"
#include "exception.h"
class Abstract_Service : public QObject
{
    Q_OBJECT
public:
    explicit Abstract_Service(QObject *parent = nullptr);
protected slots:
    virtual void run();
};

#endif // ABSTRACT_SERVICE_H
