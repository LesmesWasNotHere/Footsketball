#ifndef _ICONTROL_H
#define _ICONTROL_H

enum CONTROLS
{
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8,
    FIRE = 16,
    EXIT = 32,
    PAUSE = 64
};

class IControl 
{
    public:
        virtual ~IControl() {};
        virtual void Update() = 0;
        virtual unsigned GetState() = 0;
};

#endif