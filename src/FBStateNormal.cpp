#include "FBStateNormal.h"

#define OWN_DISTANCE = 13

FBStateNormal::FBStateNormal(FootsketBall& gameObject):_GameObject(gameObject)
{

}

bool FBStateNormal::Update(unsigned milis)
{
    return true;
}