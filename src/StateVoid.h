#ifndef _STATEVOID_H
#define _STATEVOID_H

#include "IState.h"

class StateVoid:public IState
{
    public:
        static StateVoid& Instance();

        virtual bool Update(unsigned milis);
    protected:
        StateVoid();
};

#endif