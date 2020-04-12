#include "GameCoordinates.h"

//PLAYING FIELD IS:

//UPPER LEFT  (100, 300)
//LOWER LEFT  (  0, 500)
//UPPER RIGHT (700, 300)
//LOWER RIGHT (800, 500)

//WITHOUT PERSPECTIVE, IT IS 800x200.

#define MIDDLE_FIELD (800 / 2.0)

void GameCoordinates::World2Screen(Position& position, double& x, double& y, double& zoom)
{
    zoom = 0.375 + position.y * 0.00125;
    x = MIDDLE_FIELD + ((position.x - MIDDLE_FIELD) * zoom);
    y = position.y;
}