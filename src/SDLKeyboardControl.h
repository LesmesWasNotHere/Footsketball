#ifndef _SDLKEYBOARDCONTROL_H
#define _SDLKEYBOARDCONTROL_H

#include "IControl.h"
#include <SDL2/SDL.h>

class SDLKeyboardControl: public IControl
{
    public:
        virtual void Update();
        virtual unsigned GetState();
    private:
        unsigned _State;
};

#endif