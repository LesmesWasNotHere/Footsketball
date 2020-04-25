#ifndef _POSITION_H
#define _POSITION_H

class Position 
{
    public:
        Position();       
        Position(double x, double y, double z);
        Position(const Position& position);

        double x;
        double y;
        double z;

        double SquareDistance2D(Position position) const;
        double Distance2D(Position position) const;
        double SquareDistance(Position position) const;
        double Distance(Position position) const;

        void Normalize2D();
        void Normalize();

        void Direction2D(Position other, Position& result) const;
        void Direction(Position other, Position& result) const;
};

#endif
