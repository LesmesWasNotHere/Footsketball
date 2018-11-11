#include <cmath>

#include "Position.h"

Position::Position()
{
}

Position::Position(double x, double y, double z)
{
    _X = x;
    _Y = y;
    _Z = z;
}

double Position::GetX() const
{
    return _X;
}

double Position::SetX(double x)
{
    _X = x;
}

double Position::GetY() const
{
    return _Y;
}

double Position::SetY(double y)
{
    _Y = y;
}
        
double Position::GetZ() const
{
    return _Z;
}

double Position::SetZ(double z)
{
    _Z = z;
}

double Position::SquareDistance2D(Position position) const
{
    double distX = (_X - position._X);
    double distY = (_Y - position._Y); 
    return  distX * distX + distY * distY; 
}

double Position::Distance2D(Position position) const
{
    return sqrt(SquareDistance2D(position));
}

double Position::SquareDistance(Position position) const
{
    double distZ = (_Z - position._Z);
    return SquareDistance2D(position) + distZ * distZ;
}

double Position::Distance(Position position) const
{
    return sqrt(SquareDistance(position));
}