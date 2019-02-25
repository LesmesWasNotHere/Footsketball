#ifndef _ICONTROL_H
#define _ICONTROL_H

enum CONTROLS
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    FIRE = 4
};

class IControl 
{
    public:
        virtual ~IControl() {};
        virtual void Update() = 0;
        virtual bool ControlPressed(CONTROLS control) = 0;
};

#endif