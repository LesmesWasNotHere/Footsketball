class Position 
{
    public:
        Position();
        Position(double x, double y, double z);

        double GetX() const;
        double SetX(double x);
        double GetY() const;
        double SetY(double y);
        double GetZ() const;
        double SetZ(double z);

        double SquareDistance2D(Position position) const;
        double Distance2D(Position position) const;
        double SquareDistance(Position position) const;
        double Distance(Position position) const;

    private:
        double _X;
        double _Y;
        double _Z;
}