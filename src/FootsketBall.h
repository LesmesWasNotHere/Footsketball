#ifndef _FOOTSKETBALL_H
#define _FOOTSKETBALL_H

#include "GameObject.h"

class FootsketBall:public GameObject
{
    public:
        FootsketBall(const char* spriteName);

    private:
        Animation _StopedAnimation;
};

#endif