#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "IState.h"
#include "Animation.h"
#include "Position.h"
#include <functional>

class GameObject
{
    public:
        GameObject();
        Position& GetCurrentPosition();
        Animation& GetCurrentAnimation();
        IState& GetCurrentState();
        void SetCurrentState(IState& state);
    protected:
        Position _CurrentPosition;
        std::reference_wrapper<Animation> _CurrentAnimation;
        std::reference_wrapper<IState> _CurrentState;
};

#endif