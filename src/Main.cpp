#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SpriteCache.h"
#include <iostream>

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

    SpriteCache spriteCache;

    spriteCache.Load("graphics/field.png", "FIELD");
    spriteCache.Load("graphics/ball.png", "BALL");
    spriteCache.Load("graphics/Cabueñes_Hugo.png", "CAB_HUGO");

    //Get window surface 
    screenSurface = SDL_GetWindowSurface( window ); 
    //Paint field!
    SDL_BlitSurface(spriteCache.GetSprite("FIELD"), NULL, screenSurface, NULL);
    SDL_BlitSurface(spriteCache.GetSprite("CAB_HUGO"), NULL, screenSurface, NULL);
    SDL_BlitSurface(spriteCache.GetSprite("BALL"), NULL, screenSurface, NULL);
    //Update the surface 
    SDL_UpdateWindowSurface( window ); 
    //Wait 8 seconds 
    SDL_Delay( 8000 ); 

    //Destroy window 
    SDL_DestroyWindow( window ); 
    //Quit SDL subsystems 
    SDL_Quit(); 
    return 0;
}