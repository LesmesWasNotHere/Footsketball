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
        Position& GetCurrentDirection();
        double GetCurrentSpeed();
        Animation& GetCurrentAnimation();
        IState& GetCurrentState();
        void SetCurrentState(IState& state);
        void SetCurrentSpeed(double speed);
        bool Update(unsigned milis);
    protected:
        Position _CurrentPosition;
        Position _CurrentDirection;
        double _CurrentSpeed;
        std::reference_wrapper<Animation> _CurrentAnimation;
        std::reference_wrapper<IState> _CurrentState;
};

#endif