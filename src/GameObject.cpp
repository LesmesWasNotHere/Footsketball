#include "GameObject.h"

Position& GameObject::GetCurrentPosition()
{
    return _CurrentPosition;
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