#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDLKeyboardControl.h"
#include "SDLSpriteCache.h"
#include "Animation.h"
#include "FootsketPlayer.h"
#include "GameCoordinates.h"
#include "GameSystem.h"
#include <iostream>
#include <functional>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
    //The window we'll be rendering to 
    SDL_Window* window = NULL; 
    //The surface contained by the window 
    SDL_Surface* screenSurface = NULL; 
    //Initialize SDL 
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 
    { 
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError(); 
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "could not initialize sdl2_image: " << IMG_GetError();
        return 1;
    }

    //Create window 
    window = SDL_CreateWindow( "Footsketball!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
    
    if( window == NULL ) 
    { 
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError(); 
        return 1;
    }

    SDLSpriteCache spriteCache;

    spriteCache.Load("graphics/field.png", "FIELD");
    spriteCache.Load("graphics/ball.png", "BALL");
    spriteCache.Load("graphics/Cabueñes_Hugo.png", "CAB_HUGO");

    //Get window surface 
    screenSurface = SDL_GetWindowSurface( window ); 
    int lastTicks =  SDL_GetTicks();
    int frameTicks;
    int milisFrame;
    double px = 0;
    double py = 0;

    GameCoordinates gameCoordinates;

    FootsketPlayer hugo("Hugo", "CAB_HUGO");
    hugo.GetCurrentPosition().x = 400;
    hugo.GetCurrentPosition().y = 400;

    unsigned controlState;

    while (true)
    {
        //Update SDL Events
        SDL_PumpEvents();

        GameSystem::ControlInstance().Update();  
        controlState = GameSystem::ControlInstance().GetState();  
        
        frameTicks = SDL_GetTicks();
        milisFrame = frameTicks - lastTicks;
        lastTicks = frameTicks;

        if (CONTROLS::EXIT & controlState)
            break;

        //Update object
        hugo.Update(milisFrame);

        AnimationFrame& frame = hugo.GetCurrentAnimation().GetCurrentFrame();

        //Paint field!
        SDL_BlitSurface(spriteCache.GetSprite("FIELD"), NULL, screenSurface, NULL);

        SDL_Rect srcrect;
        srcrect.x = frame.x;
        srcrect.y = frame.y;
        srcrect.w = frame.w;
        srcrect.h = frame.h;

        double x,y,zoom;
        gameCoordinates.World2Screen(hugo.GetCurrentPosition(), x, y, zoom);

        SDL_Rect destrect;
        destrect.x = x - (frame.w / 2);
        destrect.y = y - (frame.h);

        SDL_BlitSurface(spriteCache.GetSprite(frame.SpriteName), &srcrect, screenSurface, &destrect);
        //SDL_BlitSurface(spriteCache.GetSprite("BALL"), NULL, screenSurface, NULL);
        //Update the surface 
        SDL_UpdateWindowSurface( window ); 
    }

    //Destroy window 
    SDL_DestroyWindow( window ); 
    //Quit SDL subsystems 
    SDL_Quit(); 
    return 0;
}