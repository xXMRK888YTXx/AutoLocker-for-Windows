#include "mousepoint.h"

MousePoint::MousePoint() noexcept
{
    x = 0;
    y = 0;
}

MousePoint::MousePoint(POINT p) noexcept
{
    x = p.x;
    y = p.y;
}

MousePoint::MousePoint(long x, long y) noexcept
{
    setX(x);
    setY(y);
}

bool MousePoint::operator==(const MousePoint &other) noexcept
{
    return x == other.x && y == other.y;
}

void MousePoint::operator=(const MousePoint &other)
{
    setX(other.x);
    setY(other.y);
}

bool MousePoint::operator!=(const MousePoint &other) noexcept
{
    return !operator==(other);
}

QString MousePoint::toString()
{
    return "[x: "+QString::number(getX())+" y: "+QString::number(getY())+"]";
}
