#ifndef _ICONTROL_H
#define _ICONTROL_H

enum CONTROLS
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    FIRE = 4
};

class IControl 
{
    virtual ~IControl() {};
    virtual void Update() = 0;
    virtual bool ControlPressed(CONTROLS control) = 0;
};

#endif