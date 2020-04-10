#include "StateControlled.h"

StateControlled::StateControlled(GameObject& gameObject, IControl& control):_GameObject(gameObject),_Control(control)
{
}

bool StateControlled::Update(unsigned milis)
{
    const double speed = 0.05;
    int controlState = _Control.GetState();

    Position& p = _GameObject.GetCurrentPosition();

    if (CONTROLS::LEFT & controlState) {
        p.x -= speed * milis;
        //currentAnimation = std::ref(hugo4);
    }

    if (CONTROLS::RIGHT & controlState) {
        p.x += speed * milis;
        //currentAnimation = std::ref(hugo3);
    }

    if (CONTROLS::UP & controlState) {
        p.y -= speed * milis;
        //currentAnimation = std::ref(hugo2);
    }

    if (CONTROLS::DOWN & controlState) {
        p.y += speed * milis;
        //currentAnimation = std::ref(hugo1);
    }

    return true;
}
