#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDLKeyboardControl.h"
#include "SDLSpriteCache.h"
#include "SDLMatchOverlay.h"
#include "Animation.h"
#include "FootsketPlayer.h"
#include "FootsketBall.h"
#include "GameCoordinates.h"
#include "GameSystem.h"
#include "FPSCounter.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//The surface contained by the window 
SDL_Surface* screenSurface = NULL;

GameCoordinates gameCoordinates;
SDLSpriteCache spriteCache;
SDL_Rect srcrect;
SDL_Rect destrect;

void drawGameObject(GameObject& gameObject)
{
    AnimationFrame& frame = gameObject.GetCurrentAnimation().GetCurrentFrame();

    srcrect.x = frame.x;
    srcrect.y = frame.y;
    srcrect.w = frame.w;
    srcrect.h = frame.h;

    double x,y,zoom;
    gameCoordinates.World2Screen(gameObject.GetCurrentPosition(), x, y, zoom);

    destrect.x = x - (frame.w / 2);
    destrect.y = y - (frame.h);

    SDL_BlitSurface(spriteCache.GetSprite(frame.SpriteName), &srcrect, screenSurface, &destrect);
}

int drawingObjectComparer(GameObject* object1, GameObject* object2)
{
    return object1->GetCurrentPosition().y < object2->GetCurrentPosition().y;
}

int main(int argc, char* args[]) {
    //The window we'll be rendering to 
    SDL_Window* window = NULL; 
     
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

    if (TTF_Init() == -1) {
        std::cerr << "could not initialize sdl2_ttf: " << TTF_GetError();
        return 1;
    }

    //Create window 
    window = SDL_CreateWindow( "Footsketball!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
    
    if( window == NULL ) 
    { 
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError(); 
        return 1;
    }

    spriteCache.Load("graphics/field.png", "FIELD");
    spriteCache.Load("graphics/ball.png", "BALL");
    spriteCache.Load("graphics/Cabueñes_Hugo.png", "CAB_HUGO");

    //Get window surface 
    screenSurface = SDL_GetWindowSurface( window ); 
    unsigned lastTicks =  SDL_GetTicks();
    unsigned frameTicks;
    unsigned milisFrame;
    double px = 0;
    double py = 0;

    FootsketPlayer hugo("Hugo", "CAB_HUGO");
    hugo.GetCurrentPosition().x = 400;
    hugo.GetCurrentPosition().y = 400;

    FootsketBall ball("BALL");
    ball.GetCurrentPosition().x = 500;
    ball.GetCurrentPosition().y = 400;

    std::vector<GameObject*>::iterator it;
    std::vector<GameObject*> objects;
    objects.push_back(&hugo);
    objects.push_back(&ball);

    unsigned controlState;

    SDLMatchOverlay overlay;

    unsigned minMilisFrame = 16;

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

        //Update objects

        for (it = objects.begin(); it != objects.end(); ++it)
            (*it)->Update(milisFrame);

        //Paint field!
        SDL_BlitSurface(spriteCache.GetSprite("FIELD"), NULL, screenSurface, NULL);

        std::sort(objects.begin(), objects.end(), drawingObjectComparer);

        for (it = objects.begin(); it != objects.end(); ++it)
            drawGameObject(**it);

        overlay.Update(screenSurface, milisFrame);

        SDL_UpdateWindowSurface( window ); 

        unsigned frameTimePassed = SDL_GetTicks() - frameTicks;

        if (frameTimePassed < minMilisFrame)
            SDL_Delay(minMilisFrame - frameTimePassed);
    }

    //Destroy window 
    SDL_DestroyWindow( window ); 
    //Quit SDL subsystems 
    SDL_Quit(); 
    return 0;
}