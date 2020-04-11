#include "SDLKeyboardControl.h"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>

void SDLKeyboardControl::Update()
{
    _State = 0;
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
   
    if (keyboardState[SDL_SCANCODE_UP])
        _State |= UP;

    if (keyboardState[SDL_SCANCODE_DOWN])
        _State |= DOWN;

    if (keyboardState[SDL_SCANCODE_LEFT])
        _State |= LEFT;

    if (keyboardState[SDL_SCANCODE_RIGHT])
        _State |= RIGHT;

    if (keyboardState[SDL_SCANCODE_SPACE])
        _State |= FIRE;

    if (keyboardState[SDL_SCANCODE_ESCAPE])
        _State |= EXIT;

    if (keyboardState[SDL_SCANCODE_H])
        _State |= PAUSE;
}

unsigned SDLKeyboardControl::GetState()
{
    return _State;
}