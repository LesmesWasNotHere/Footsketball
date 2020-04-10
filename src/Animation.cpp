#include "Animation.h"
#include <cassert>

Animation::Animation(std::string name, unsigned fps):_Name(name), _Frames(), _CurrentFrame(0) 
{
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

AnimationFrame& Animation::GetCurrentFrame()
{
    assert(_Frames.size());
    return _Frames[_CurrentFrame];
}

void Animation::SetFPS(unsigned fps)
{
    assert(fps <= 100);

    _MilisPerFrame = fps ? (1000 / fps) : 0;
}

void Animation::Update(unsigned milis)
{
    if (_MilisPerFrame)
    {
        //Add milis to current milis
        _CurrentMilis += milis;
        //sum frames passed
        _CurrentFrame += (_CurrentMilis / _MilisPerFrame);
        //adjust frames to the animation size
        _CurrentFrame %= _Frames.size();
        //Adjust _CurrentMiles to the remaining of the next frame
        _CurrentMilis %= _MilisPerFrame;
    }
}

void Animation::Reset()
{
    _CurrentMilis = 0;
    _CurrentFrame = 0;
}

void Animation::AddFrame(const char* spriteName, int x, int y, int w, int h)
{
    AnimationFrame frame;
    frame.SpriteName = spriteName;
    frame.x = x;
    frame.y = y;
    frame.w = w;
    frame.h = h;
    _Frames.push_back(frame);
};