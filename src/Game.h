#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include "Scene.h"

class Game
{
    public:
        void PushScene(Scene& scene);
        Scene& GetCurrentScene();
        bool Loop(unsigned milis);
    protected:
        std::vector<std::reference_wrapper<Scene>> _Scenes;
        std::reference_wrapper<Scene> _CurrentScene;
};

#endif