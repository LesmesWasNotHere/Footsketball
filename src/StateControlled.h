#ifndef _STATE_CONTROLLED_H
#define _STATE_CONTROLLED_H

#include "IState.h"
#include "IControl.h"

class FootsketPlayer;

class StateControlled: public IState
{
    public:
        StateControlled(FootsketPlayer& gameObject, IControl& control);

        virtual bool Update(unsigned milis);
    protected:
        IControl& _Control;
        FootsketPlayer& _GameObject;
        unsigned _LastControlState;
};

#endif