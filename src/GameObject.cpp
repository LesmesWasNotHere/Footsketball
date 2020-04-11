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

bool GameObject::Update(unsigned milis)
{
    bool result = _CurrentState.get().Update(milis);
    _CurrentAnimation.get().Update(milis);
    return result;
}