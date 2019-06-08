#include "Scene.h"

Scene::Scene():_GameObjects()
{
}

Scene::~Scene()
{
}

void Scene::AddGameObject(GameObject& gameObject)
{
    _GameObjects.push_back(gameObject);
}

void Scene::RemoveGameObject(GameObject& gameObject)
{
    for(std::vector<std::reference_wrapper<GameObject>>::iterator i = _GameObjects.begin();i != _GameObjects.end();++i)
    {
        if (&(i->get()) == &gameObject)
        {
            _GameObjects.erase(i);
            break;
        }
    }
}

bool Scene::OnLoop(unsigned milis)
{
    for(std::vector<std::reference_wrapper<GameObject>>::iterator i = _GameObjects.begin();i != _GameObjects.end();++i)
    {
        if (!i->get().GetCurrentState().Update(milis))
            i = _GameObjects.erase(i);
    }
    return true;
}

void Scene::OnStart()
{
}

void Scene::OnEnd()
{
}