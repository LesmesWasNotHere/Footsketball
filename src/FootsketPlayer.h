#ifndef _FOOTSKETPLAYER_H
#define _FOOTSKETPLAYER_H

#include "GameObject.h"

class FootsketPlayer:public GameObject
{
    public:
        FootsketPlayer(const char* spriteName);

        void ActivateRunUpAnimation();
        void ActivateRunDownAnimation();
        void ActivateRunLeftAnimation();
        void ActivateRunRightAnimation();
        void ActivateStopedUpAnimation();
        void ActivateStopedDownAnimation();
        void ActivateStopedLeftAnimation();
        void ActivateStopedRightAnimation();
    protected:
        const unsigned _Fps = 8;
        Animation _RunUpAnimation;
        Animation _RunDownAnimation;
        Animation _RunLeftAnimation;
        Animation _RunRightAnimation;
};

#endif