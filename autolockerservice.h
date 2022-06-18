#ifndef AUTOLOCKERSERVICE_H
#define AUTOLOCKERSERVICE_H

#include <QObject>
#include "abstract_service.h"
#include "mousepoint.h"
#include <QTimer>
class AutoLockerService : public Abstract_Service
{
    Q_OBJECT
public:
    explicit AutoLockerService(SettingsService *settingsService,Logger *logger,QObject *parent = nullptr);
    const QString SERVICE_NAME = "AutoLockerService";
private:
    MousePoint getPosMouse();
    QTimer *idleTimer;
    void changeStateService(ServiceState state, QString SERVICE_NAME) override;
    QThread *checkMouseThread;
    QThread *checkKeyBoardThread;
    void checkKeyBoard();
    int idleTimeOut_ms;
signals:
    void startT(int s);
    void resetT();
    void stopT();
private slots:
    void run() override;
    void pcInIdleStatusSlot();
    void startTimer(int s);
    void resetTimer();
    void stopTimer();
public slots:
    void changeStateServiceSlot(QString service, int state) noexcept override;

};

#endif // AUTOLOCKERSERVICE_H
