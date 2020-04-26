#ifndef _FB_STATE_NORMAL_H
#define _FB_STATE_NORMAL_H

#include "FootsketBall.h"

class FBStateNormal
{
    public:
        FBStateNormal(FootsketBall& gameObject);

        virtual bool Update(unsigned milis);
    protected:
        FootsketBall& _GameObject;
};

#endif