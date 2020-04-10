#include "StateVoid.h"

StateVoid& StateVoid::Instance()
{
    static StateVoid instance;
    return instance;
}

bool StateVoid::Update(unsigned milis)
{
    return true;
}

StateVoid::StateVoid()
{
}