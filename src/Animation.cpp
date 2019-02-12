#include "Animation.h"
#include <cassert>

Animation::Animation(std::string name, unsigned numFrames, unsigned fps):_Name(name), _NumFrames(numFrames) 
{
    assert(numFrames > 0);
    assert(name.length() > 0);
    SetFPS(fps);
}

Animation::~Animation()
{    
}

std::string Animation::GetName()
{
    return _Name;
} 

unsigned Animation::GetCurrentFrame()
{
    return _CurrentFrame;
}

void Animation::SetFPS(unsigned fps)
{
    assert(fps > 0);
    assert(fps <= 1000);

    _MilisPerFrame = (1000 / fps);
}

void Animation::Update(unsigned milis)
{
    //Add milis to current milis
    _CurrentMilis += milis;
    //sum frames passed
    _CurrentFrame += (_CurrentMilis / _MilisPerFrame);
    //adjust frames to the animation size
    _CurrentFrame %= _NumFrames;
    //Adjust _CurrentMiles to the remaining of the next frame
    _CurrentMilis %= _MilisPerFrame;
}

void Animation::Reset()
{
    _CurrentMilis = 0;
    _CurrentFrame = 0;
}