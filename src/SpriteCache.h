#include "SDL2/SDL.h"

class SpriteCache
{
    public:
        SpriteCache();
        ~SpriteCache();

        bool Load(const char* path, const char* id);
        SDL_Surface* GetSprite(const char* id);
};