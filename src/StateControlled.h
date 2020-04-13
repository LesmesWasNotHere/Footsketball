#ifndef _STATE_CONTROLLED_H
#define _STATE_CONTROLLED_H

#include "IState.h"
#include "IControl.h"

class FootsketPlayer;

class StateControlled: public IState
{
    public:
        StateControlled(FootsketPlayer& gameObject);

        virtual bool Update(unsigned milis);
    protected:
        FootsketPlayer& _GameObject;
        unsigned _LastControlState;
};

#endif