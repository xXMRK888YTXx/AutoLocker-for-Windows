#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <QDebug>
class Exception
{
public:
    Exception(QString ex);
    void what(QString ex);
private:
};

#endif // EXCEPTION_H
