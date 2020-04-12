#include <cmath>

#include "Position.h"

Position::Position()
{
}

Position::Position(double X, double Y, double Z)
{
    x = X;
    y = Y;
    z = Z;
}

double Position::SquareDistance2D(Position position) const
{
    double distX = (x - position.x);
    double distY = (y - position.y); 
    return  distX * distX + distY * distY; 
}

double Position::Distance2D(Position position) const
{
    return sqrt(SquareDistance2D(position));
}

double Position::SquareDistance(Position position) const
{
    double distZ = (z - position.z);
    return SquareDistance2D(position) + distZ * distZ;
}

double Position::Distance(Position position) const
{
    return sqrt(SquareDistance(position));
}

void Position::Normalize2D()
{
  if (!x && !y)
    return;

  Position origin(0,0,0);
  double module = Distance2D(origin);
  x /= module;
  y /= module;
}

void Position::Normalize()
{
  if (!x && !y && !z)
    return;

  Position origin(0,0,0);
  double module = Distance(origin);
  x /= module;
  y /= module;
  z /= module;
}

void Position::Direction2D(Position other, Position& result) const
{
  result.x = (other.x - x);
  result.y = (other.y - y);
  result.Normalize2D();
}

void Position::Direction(Position other, Position& result) const
{
  result.x = (other.x - x);
  result.y = (other.y - y);
  result.z = (other.z - z);
  result.Normalize();
}
