#ifndef _FP_STATE_CONTROLLED_H
#define _FP_STATE_CONTROLLED_H

#include "IState.h"
#include "IControl.h"

class FootsketPlayer;

class FPStateControlled: public IState
{
    public:
        FPStateControlled(FootsketPlayer& gameObject);

        virtual bool Update(unsigned milis);
    protected:
        FootsketPlayer& _GameObject;
        unsigned _LastControlState;
};

#endif