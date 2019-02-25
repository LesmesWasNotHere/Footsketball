#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <string>
#include <vector>
#include "AnimationFrame.h"

class Animation
{
    public:
        Animation(std::string name, unsigned fps);
        ~Animation();

        std::string GetName();
        AnimationFrame GetCurrentFrame();
        void SetFPS(unsigned fps);
        
        void Update(unsigned milis);
        void Reset();
        void AddFrame(const char* spriteName, int x, int y, int w, int z);
    protected:
        std::string _Name;        
        std::vector<AnimationFrame> _Frames;
        unsigned _CurrentFrame;
        unsigned _CurrentMilis;
        unsigned _MilisPerFrame;
};

#endif