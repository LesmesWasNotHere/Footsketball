#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDLKeyboardControl.h"
#include "SDLSpriteCache.h"
#include "Animation.h"
#include "FootsketPlayer.h"
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

    SDLKeyboardControl control;

    //Get window surface 
    screenSurface = SDL_GetWindowSurface( window ); 
    int lastTicks =  SDL_GetTicks();
    int frameTicks;
    int milisFrame;
    double px = 0;
    double py = 0;

    FootsketPlayer hugo("CAB_HUGO");
    int lastControlState;
    int controlState;

    while (true)
    {
        //Update SDL Events
        SDL_PumpEvents();

        control.Update();  
        controlState = control.GetState();  
        
        frameTicks = SDL_GetTicks();
        milisFrame = frameTicks - lastTicks;
        lastTicks = frameTicks;

        //Chech if some key is pressed
        if (controlState)
        {
            if (CONTROLS::EXIT & controlState)
                break;

            if (CONTROLS::LEFT & controlState) {
                px -= 0.05 * milisFrame;
                hugo.ActivateRunLeftAnimation();
            }

            if (CONTROLS::RIGHT & controlState) {
                px += 0.05 * milisFrame;
                hugo.ActivateRunRightAnimation();
            }

            if (CONTROLS::UP & controlState) {
                py -= 0.05 * milisFrame;
                hugo.ActivateRunUpAnimation();
            }

            if (CONTROLS::DOWN & controlState) {
                py += 0.05 * milisFrame;
                hugo.ActivateRunDownAnimation();
            }
        }
        else
        {
            if (CONTROLS::UP & lastControlState)
                hugo.ActivateStopedUpAnimation();
            else
                if (CONTROLS::DOWN & lastControlState)
                    hugo.ActivateStopedDownAnimation();
                else
                    if (CONTROLS::LEFT & lastControlState)
                        hugo.ActivateStopedLeftAnimation();
                    else
                        if (CONTROLS::RIGHT & lastControlState) 
                            hugo.ActivateStopedRightAnimation();            
        }

        //Update animation
        hugo.GetCurrentAnimation().Update(milisFrame);

        AnimationFrame& frame = hugo.GetCurrentAnimation().GetCurrentFrame();

        //Paint field!
        SDL_BlitSurface(spriteCache.GetSprite("FIELD"), NULL, screenSurface, NULL);

        SDL_Rect srcrect;
        srcrect.x = frame.x;
        srcrect.y = frame.y;
        srcrect.w = frame.w;
        srcrect.h = frame.h;

        SDL_Rect destrect;
        destrect.x = px;
        destrect.y = py;

        SDL_BlitSurface(spriteCache.GetSprite(frame.SpriteName), &srcrect, screenSurface, &destrect);
        //SDL_BlitSurface(spriteCache.GetSprite("BALL"), NULL, screenSurface, NULL);
        //Update the surface 
        SDL_UpdateWindowSurface( window ); 

        lastControlState = controlState;
    }

    //Destroy window 
    SDL_DestroyWindow( window ); 
    //Quit SDL subsystems 
    SDL_Quit(); 
    return 0;
}