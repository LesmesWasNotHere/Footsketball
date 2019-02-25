#include "SDL2/SDL.h"
#include <map>
#include <string>

class SpriteCache
{
    public:
        SpriteCache();
        ~SpriteCache();

        bool Load(const char* path, const char* id);
        SDL_Surface* GetSprite(const char* id);

    protected:
        std::map<std::string, SDL_Surface*> _Cache;
};