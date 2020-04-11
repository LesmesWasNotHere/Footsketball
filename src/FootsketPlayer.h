#ifndef _FOOTSKETPLAYER_H
#define _FOOTSKETPLAYER_H

#include "GameObject.h"
#include "StateControlled.h"
#include "IControl.h"

class FootsketPlayer:public GameObject
{
    public:
        FootsketPlayer(const char* spriteName, IControl& control);

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

        //Animations:
        Animation _RunUpAnimation;
        Animation _RunDownAnimation;
        Animation _RunLeftAnimation;
        Animation _RunRightAnimation;
        Animation _StopedUpAnimation;
        Animation _StopedDownAnimation;
        Animation _StopedLeftAnimation;
        Animation _StopedRightAnimation;
        //States:
        StateControlled _StateControlled;
};

#endif