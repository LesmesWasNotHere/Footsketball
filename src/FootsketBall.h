#ifndef _FOOTSKETBALL_H
#define _FOOTSKETBALL_H

#include "GameObject.h"
#include "FootsketPlayer.h"

class FootsketBall:public GameObject
{
    public:
        FootsketBall(const char* spriteName);

        const FootsketPlayer* GetOwner();

    private:
        Animation _StopedAnimation;
        FootsketPlayer* _Owner;
};

#endif