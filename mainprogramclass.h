#ifndef MAINPROGRAMCLASS_H
#define MAINPROGRAMCLASS_H

#include <QObject>

class MainProgramClass : public QObject
{
    Q_OBJECT
public:
    explicit MainProgramClass(QObject *parent = nullptr);

signals:

};

#endif // MAINPROGRAMCLASS_H
