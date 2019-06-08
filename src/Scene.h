#ifndef _SCENE_H
#define _SCENE_H

#include <vector>
#include "GameObject.h"

class Scene 
{
    public:
        Scene();
        virtual ~Scene();
        void AddGameObject(GameObject& gameObject);
        void RemoveGameObject(GameObject& gameObject);
        virtual bool OnLoop(unsigned milis);
        virtual void OnStart();
        virtual void OnEnd();
    protected:
        std::vector<std::reference_wrapper<GameObject>> _GameObjects;
};

#endif