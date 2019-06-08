#ifndef _STATE_CONTROLLED_H
#define _STATE_CONTROLLED_H

#include "IState.h"
#include "IControl.h"
#include "GameObject.h"

class StateControlled: public IState
{
    public:
        StateControlled(GameObject& gameObject, IControl& control);

        virtual bool Update(unsigned milis);
    protected:
        IControl& _Control;
        GameObject& _GameObject;
};

#endif