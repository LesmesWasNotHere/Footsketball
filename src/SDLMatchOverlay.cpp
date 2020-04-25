#include "SDLMatchOverlay.h"
#include <cstdlib>

SDLMatchOverlay::SDLMatchOverlay()
{
    _TopBarFont = TTF_OpenFont("fonts/DejaVuSansMono.ttf", 16);

    if(!_TopBarFont) 
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        std::abort();
    }

    _TopBarFontColor = {80, 80, 200};
}

SDLMatchOverlay::~SDLMatchOverlay()
{
    TTF_CloseFont(_TopBarFont);
}

void SDLMatchOverlay::Update(SDL_Surface* screenSurface, unsigned milisFrame)
{
    char fpsMessage[10];

    _FPSCounter.Update(milisFrame);

    sprintf(fpsMessage, "FPS:%3d", _FPSCounter.GetFPS());
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(_TopBarFont, fpsMessage, _TopBarFontColor); 
    
    SDL_Rect destRect;
    destRect.x = screenSurface->w - surfaceMessage->w - 10;
    destRect.y = 10;

    SDL_BlitSurface(surfaceMessage, NULL, screenSurface, &destRect);

    SDL_FreeSurface(surfaceMessage);
}