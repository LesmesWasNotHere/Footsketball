#ifndef _GAMECOORDINATES_H
#define _GAMECOORDINATES_H

#include "Position.h"

class GameCoordinates
{
    public:
        void World2Screen(Position& position, double& x, double& y, double& zoom);
};

#endif