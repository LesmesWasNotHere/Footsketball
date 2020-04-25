#ifndef _SDL_MATCH_OVERLAY_H
#define _SDL_MATCH_OVERLAY_H

#include "FPSCounter.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

class SDLMatchOverlay
{
    public:
        SDLMatchOverlay();
        ~SDLMatchOverlay();

        void Update(SDL_Surface* screenSurface, unsigned milisFrame);
    private:
        TTF_Font* _TopBarFont;
        SDL_Color _TopBarFontColor;
        FPSCounter _FPSCounter;
};

#endif