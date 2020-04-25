#include "GameObject.h"
#include "StateVoid.h"
#include "AnimationVoid.h"

GameObject::GameObject():_CurrentState(StateVoid::Instance()),_CurrentAnimation(AnimationVoid::Instance())
{
}

Position& GameObject::GetCurrentPosition()
{
    return _CurrentPosition;
}

Position& GameObject::GetCurrentDirection()
{
    return _CurrentDirection;
}

double GameObject::GetCurrentSpeed()
{
    return _CurrentSpeed;
}

Animation& GameObject::GetCurrentAnimation()
{
    return _CurrentAnimation;
}

IState& GameObject::GetCurrentState()
{
    return _CurrentState;
}

void GameObject::SetCurrentState(IState& state)
{
    _CurrentState = state;
}

void GameObject::SetCurrentSpeed(double speed)
{
    _CurrentSpeed = speed;
}

bool GameObject::Update(unsigned milis)
{
    bool result = _CurrentState.get().Update(milis);
    _CurrentAnimation.get().Update(milis);
    return result;
}