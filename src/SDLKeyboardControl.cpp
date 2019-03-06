#include "SDLKeyboardControl.h"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>

void SDLKeyboardControl::Update()
{
    _KeyboardState = SDL_GetKeyboardState(NULL);
}

bool SDLKeyboardControl::ControlPressed(CONTROLS control)
{
    switch(control)
    {
        case UP:
            return _KeyboardState[SDL_SCANCODE_UP];
        case DOWN:
            return _KeyboardState[SDL_SCANCODE_DOWN];
        case LEFT:
            return _KeyboardState[SDL_SCANCODE_LEFT];
        case RIGHT:
            return _KeyboardState[SDL_SCANCODE_RIGHT];
        case FIRE:
            return _KeyboardState[SDL_SCANCODE_SPACE];
        case EXIT:
            return _KeyboardState[SDL_SCANCODE_ESCAPE];
        case PAUSE:
            return _KeyboardState[SDL_SCANCODE_H];
    }
    return false;
}