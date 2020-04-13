#include "GameSystem.h"
#include "SDLKeyboardControl.h"

IControl& GameSystem::ControlInstance()
{
    static SDLKeyboardControl instance;
    return instance;
}