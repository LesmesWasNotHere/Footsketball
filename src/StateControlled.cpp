#include "StateControlled.h"

StateControlled::StateControlled(GameObject& gameObject, IControl& control):_GameObject(gameObject),_Control(control)
{
}

bool StateControlled::Update(unsigned milis)
{
    const double speed = 0.05;

    Position& p = _GameObject.GetCurrentPosition();

    if (_Control.ControlPressed(CONTROLS::LEFT)) {
        p.SetX(p.GetX() - speed * milis);
        //currentAnimation = std::ref(hugo4);
    }

    if (_Control.ControlPressed(CONTROLS::RIGHT)) {
        p.SetX(p.GetX() + speed * milis);
        //currentAnimation = std::ref(hugo3);
    }

    if (_Control.ControlPressed(CONTROLS::UP)) {
        p.SetY(p.GetY() - speed * milis);
        //currentAnimation = std::ref(hugo2);
    }

    if (_Control.ControlPressed(CONTROLS::DOWN)) {
        p.SetY(p.GetY() + speed * milis);
        //currentAnimation = std::ref(hugo1);
    }

    return true;
}
