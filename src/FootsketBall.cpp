#include "FootsketBall.h"

FootsketBall::FootsketBall(const char* spriteName):_StopedAnimation("STOPED", 0)
{
    _StopedAnimation.AddFrame(spriteName, 0, 0, 11, 10);

    _CurrentAnimation = std::ref(_StopedAnimation);
}