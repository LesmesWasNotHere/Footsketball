#include "SDLSpriteCache.h" 
#include "SDL2/SDL_image.h"
#include <cassert>

SDLSpriteCache::SDLSpriteCache():_Cache()
{
}

SDLSpriteCache::~SDLSpriteCache()
{
    for (std::map<std::string,SDL_Surface*>::iterator i=_Cache.begin(); i!=_Cache.end(); ++i)
    {
        SDL_FreeSurface(i->second);
    }
}

bool SDLSpriteCache::Load(const char* path, const char* id)
{
    assert(!_Cache.count(id));

    SDL_Surface* img = IMG_Load(path);

    if (img)
    {
        _Cache[id] = img;
        return true;
    }

    return false;
}

SDL_Surface* SDLSpriteCache::GetSprite(const char* id)
{
    std::map<std::string,SDL_Surface*>::iterator i = _Cache.find(id);

    assert(i != _Cache.end());

    return i->second;
}