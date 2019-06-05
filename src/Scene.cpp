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
    for(std::vector<GameObject&>::iterator i = _GameObjects.begin();i != _GameObjects.end();++i)
    {
        if (&(*i) == &gameObject)
        {
            i->erase();
            break;
        }
    }
}

bool Scene::OnLoop(unsigned milis)
{
    for(std::vector<GameObject&>::iterator i = _GameObjects.begin();i != _GameObjects.end();++i)
        i->GetCurrentState().Update(milis);
}

void Scene::OnStart()
{
}

void Scene::OnEnd()
{
}