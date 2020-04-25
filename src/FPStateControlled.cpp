#include "FPStateControlled.h"
#include "FootsketPlayer.h"
#include "GameSystem.h"

FPStateControlled::FPStateControlled(FootsketPlayer& gameObject):_GameObject(gameObject),_LastControlState(0)
{
}

bool FPStateControlled::Update(unsigned milis)
{
    const double speed = 0.05;
    unsigned controlState =  GameSystem::ControlInstance().GetState();

    Position& p = _GameObject.GetCurrentPosition();
    Position& direction = _GameObject.GetCurrentDirection();
    direction.x = 0;
    direction.y = 0;

    //Chech if some key is pressed
    if (controlState)
    {    
        double coeficient = speed * milis;

        if (CONTROLS::LEFT & controlState) {
            direction.x = -1.;
            _GameObject.ActivateRunLeftAnimation();
        }

        if (CONTROLS::RIGHT & controlState) {
            direction.x = 1.;
            _GameObject.ActivateRunRightAnimation();
        }

        if (CONTROLS::UP & controlState) {
            direction.y = -1.;
            _GameObject.ActivateRunUpAnimation();
        }

        if (CONTROLS::DOWN & controlState) {
            direction.y = 1.;
            _GameObject.ActivateRunDownAnimation();
        }

        direction.Normalize();
        
        p.x += direction.x * coeficient;
        p.y += direction.y * coeficient;

        _GameObject.SetCurrentSpeed(speed);
    }
    else
    {
        if (CONTROLS::UP & _LastControlState)
            _GameObject.ActivateStopedUpAnimation();
        else
            if (CONTROLS::DOWN & _LastControlState)
                _GameObject.ActivateStopedDownAnimation();
            else
                if (CONTROLS::LEFT & _LastControlState)
                    _GameObject.ActivateStopedLeftAnimation();
                else
                    if (CONTROLS::RIGHT & _LastControlState) 
                        _GameObject.ActivateStopedRightAnimation();          
        _GameObject.SetCurrentSpeed(0);  
    }

    _LastControlState = controlState;

    if (p.x > 800.0)
        p.x = 800.0;

    if (p.x < 0.0)
        p.x = 0.0;

    if (p.y > 500.0)
        p.y = 500.0;

    if (p.y < 300.0)
        p.y = 300.0;

    return true;
}
