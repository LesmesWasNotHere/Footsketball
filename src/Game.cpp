#include "Game.h"

#include <assert.h>

void Game::PushScene(Scene& scene)
{
    _Scenes.push_back(scene);
    _CurrentScene = scene;
}

Scene& Game::GetCurrentScene()
{
    assert(_Scenes.size() > 0);

    return _CurrentScene;
}

bool Game::Loop(unsigned milis)
{
    assert(_Scenes.size() > 0);

    if (!_CurrentScene.get().OnLoop(milis))
    {
        _Scenes.pop_back();
        if (_Scenes.size() > 0)
        {
            _CurrentScene = *(_Scenes.rend());
            return true;
        }
        else
            return false;
    }
}