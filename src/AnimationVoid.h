#ifndef _ANIMATION_VOID_H
#define _ANIMATION_VOID_H

#include "Animation.h"

class AnimationVoid:public Animation
{
    public:
        static AnimationVoid Instance;

    protected:
        AnimationVoid();
};

#endif