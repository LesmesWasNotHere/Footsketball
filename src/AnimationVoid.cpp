#include "AnimationVoid.h"

AnimationVoid& AnimationVoid::Instance()
{
    static AnimationVoid instance;
    return instance;
}

AnimationVoid::AnimationVoid():Animation("void", 0)
{
}