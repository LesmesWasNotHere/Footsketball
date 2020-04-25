#include "FPSCounter.h"

FPSCounter::FPSCounter():_BufferPosition(0), _BufferSum(0)
{
    for(int i=0; i< BUFFER_SIZE; ++i)
        _Buffer[i] = 0;
}

void FPSCounter::Update(unsigned lastFrameMilis)
{
    unsigned currentFrameFPS = 1000 / lastFrameMilis;
    _BufferSum += currentFrameFPS - _Buffer[_BufferPosition];
    _Buffer[_BufferPosition] = currentFrameFPS;
    ++_BufferPosition %= BUFFER_SIZE;
}

unsigned FPSCounter::GetFPS()
{
    return _BufferSum / BUFFER_SIZE;
}