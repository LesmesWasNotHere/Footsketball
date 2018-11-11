#include "IState.h"
#include "IAnimation.h"
#include "Position.h"

class GameObject
{
    public:
        Position GetCurrentPosition();
        IAnimation GetCurrentAnimation();
        IState GetCurrentState();
        void SetCurrentState(State state);
    private:
        Position _CurrentPosition;
        IAnimation _CurrentAnimation;
        IState _CurrentState;
}