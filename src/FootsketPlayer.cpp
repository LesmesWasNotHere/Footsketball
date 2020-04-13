#include "FootsketPlayer.h"

FootsketPlayer::FootsketPlayer(const char* name, const char* spriteName):
                                                    _Name(name),
                                                    _RunUpAnimation("RUN_UP", _Fps), 
                                                    _RunDownAnimation("RUN_DOWN", _Fps), 
                                                    _RunLeftAnimation("RUN_LEFT", _Fps),
                                                    _RunRightAnimation("RUN_RIGHT", _Fps),
                                                    _StopedUpAnimation("STOPED_UP", _Fps), 
                                                    _StopedDownAnimation("STOPED_DOWN", _Fps), 
                                                    _StopedLeftAnimation("STOPED_LEFT", _Fps),
                                                    _StopedRightAnimation("STOPED_RIGHT", _Fps),
                                                    _StateControlled(*this)
{
    _RunUpAnimation.AddFrame(spriteName, 14, 30, 14, 30);
    _RunUpAnimation.AddFrame(spriteName, 28, 30, 14, 30);
    _RunUpAnimation.AddFrame(spriteName, 42, 30, 14, 30);
    _RunUpAnimation.AddFrame(spriteName, 56, 30, 14, 30);

    _RunDownAnimation.AddFrame(spriteName, 14, 0, 14, 30);
    _RunDownAnimation.AddFrame(spriteName, 28, 0, 14, 30);
    _RunDownAnimation.AddFrame(spriteName, 42, 0, 14, 30);
    _RunDownAnimation.AddFrame(spriteName, 56, 0, 14, 30);

    _RunLeftAnimation.AddFrame(spriteName, 14, 90, 14, 30);
    _RunLeftAnimation.AddFrame(spriteName, 28, 90, 14, 30);
    _RunLeftAnimation.AddFrame(spriteName, 42, 90, 14, 30);
    _RunLeftAnimation.AddFrame(spriteName, 56, 90, 14, 30);

    _RunRightAnimation.AddFrame(spriteName, 14, 60, 14, 30);
    _RunRightAnimation.AddFrame(spriteName, 28, 60, 14, 30);
    _RunRightAnimation.AddFrame(spriteName, 42, 60, 14, 30);
    _RunRightAnimation.AddFrame(spriteName, 56, 60, 14, 30);

    _StopedUpAnimation.AddFrame(spriteName, 0, 30, 14, 30);

    _StopedDownAnimation.AddFrame(spriteName, 0, 0, 14, 30);

    _StopedLeftAnimation.AddFrame(spriteName, 0, 90, 14, 30);

    _StopedRightAnimation.AddFrame(spriteName, 0, 60, 14, 30);

    ActivateStopedRightAnimation();

    SetCurrentState(_StateControlled);
}

void FootsketPlayer::ActivateRunUpAnimation()
{
    _CurrentAnimation = std::ref(_RunUpAnimation);
}

void FootsketPlayer::ActivateRunDownAnimation()
{
    _CurrentAnimation = std::ref(_RunDownAnimation);
}

void FootsketPlayer::ActivateRunLeftAnimation()
{
    _CurrentAnimation = std::ref(_RunLeftAnimation);
}

void FootsketPlayer::ActivateRunRightAnimation()
{
    _CurrentAnimation = std::ref(_RunRightAnimation);
}
        
void FootsketPlayer::ActivateStopedUpAnimation()
{
    _CurrentAnimation = std::ref(_StopedUpAnimation);
}

void FootsketPlayer::ActivateStopedDownAnimation()
{
    _CurrentAnimation = std::ref(_StopedDownAnimation);
}
    
void FootsketPlayer::ActivateStopedLeftAnimation()
{
    _CurrentAnimation = std::ref(_StopedLeftAnimation);
}

void FootsketPlayer::ActivateStopedRightAnimation()
{
    _CurrentAnimation = std::ref(_StopedRightAnimation);
}