#ifndef _SPRITECACHE_H
#define _SPRITECACHE_H

#include "SDL2/SDL.h"
#include <map>
#include <string>

class SDLSpriteCache
{
    public:
        SDLSpriteCache();
        ~SDLSpriteCache();

        bool Load(const char* path, const char* id);
        SDL_Surface* GetSprite(const char* id);

    protected:
        std::map<std::string, SDL_Surface*> _Cache;
};

#endif