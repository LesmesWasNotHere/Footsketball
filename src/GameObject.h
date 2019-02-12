#include "IState.h"
#include "Animation.h"
#include "Position.h"

class GameObject
{
    public:
        Position& GetCurrentPosition();
        Animation& GetCurrentAnimation();
        IState& GetCurrentState();
        void SetCurrentState(IState& state);
    private:
        Position& _CurrentPosition;
        Animation& _CurrentAnimation;
        IState& _CurrentState;
};