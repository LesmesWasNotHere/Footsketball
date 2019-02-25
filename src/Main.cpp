#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDLSpriteCache.h"
#include "Animation.h"
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

    Animation hugo1("RUN_DOWN", 8);
    hugo1.AddFrame("CAB_HUGO", 14, 0, 14, 30);
    hugo1.AddFrame("CAB_HUGO", 28, 0, 14, 30);
    hugo1.AddFrame("CAB_HUGO", 42, 0, 14, 30);
    hugo1.AddFrame("CAB_HUGO", 56, 0, 14, 30);

    Animation hugo2("RUN_UP", 8);
    hugo2.AddFrame("CAB_HUGO", 14, 30, 14, 30);
    hugo2.AddFrame("CAB_HUGO", 28, 30, 14, 30);
    hugo2.AddFrame("CAB_HUGO", 42, 30, 14, 30);
    hugo2.AddFrame("CAB_HUGO", 56, 30, 14, 30);

    Animation hugo3("RUN_RIGHT", 8);
    hugo3.AddFrame("CAB_HUGO", 14, 60, 14, 30);
    hugo3.AddFrame("CAB_HUGO", 28, 60, 14, 30);
    hugo3.AddFrame("CAB_HUGO", 42, 60, 14, 30);
    hugo3.AddFrame("CAB_HUGO", 56, 60, 14, 30);

    Animation hugo4("RUN_LEFT", 8);
    hugo4.AddFrame("CAB_HUGO", 14, 90, 14, 30);
    hugo4.AddFrame("CAB_HUGO", 28, 90, 14, 30);
    hugo4.AddFrame("CAB_HUGO", 42, 90, 14, 30);
    hugo4.AddFrame("CAB_HUGO", 56, 90, 14, 30);

    //Get window surface 
    screenSurface = SDL_GetWindowSurface( window ); 
    int lastTicks =  SDL_GetTicks();
    int frameTicks;
    int milisFrame;
    for (int i=0; i<2000; ++i)
    {
        frameTicks = SDL_GetTicks();
        milisFrame = frameTicks - lastTicks;
        lastTicks = frameTicks;

        //Update animation
        hugo3.Update(milisFrame);

        AnimationFrame frame = hugo3.GetCurrentFrame();

        //Paint field!
        SDL_BlitSurface(spriteCache.GetSprite("FIELD"), NULL, screenSurface, NULL);

        SDL_Rect rect;
        rect.x = frame.x;
        rect.y = frame.y;
        rect.w = frame.w;
        rect.h = frame.h;

        SDL_BlitSurface(spriteCache.GetSprite(frame.SpriteName), &rect, screenSurface, NULL);
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