#ifndef MOUSEPOINT_H
#define MOUSEPOINT_H

#include "windows.h"
#include <QString>
class MousePoint
{
public:
    MousePoint() noexcept;
    MousePoint(POINT p) noexcept;
    MousePoint(long x,long y) noexcept;
    long getX() noexcept {return x;};
    long getY() noexcept {return y;};
    void setX(long x) noexcept {this->x = x;};
    void setY(long y) noexcept {this->y = y;};
    bool operator==(const MousePoint &other) noexcept;
    void operator=(const MousePoint &other);
    QString operator<<(const MousePoint &point){return toString();};
    QString toString();
private:
    long x;
    long y;
};

#endif // MOUSEPOINT_H
