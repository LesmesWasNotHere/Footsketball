#include "FPSCounter.h"
#include <unistd.h>

FPSCounter::FPSCounter():_BufferPosition(0), _BufferSum(0)
{
    _MinMilisFrame = 10;
    for(int i=0; i< BUFFER_SIZE; ++i)
        _Buffer[i] = 0;
}

void FPSCounter::Update(unsigned lastFrameMilis)
{
    if (lastFrameMilis)
    {
        unsigned currentFrameFPS = 1000 / lastFrameMilis;
        _BufferSum += currentFrameFPS - _Buffer[_BufferPosition];
        _Buffer[_BufferPosition] = currentFrameFPS;
        ++_BufferPosition %= BUFFER_SIZE;
    }

    if (lastFrameMilis < _MinMilisFrame)
        usleep((_MinMilisFrame - lastFrameMilis) * 1000);
}

unsigned FPSCounter::GetFPS()
{
    return _BufferSum / BUFFER_SIZE;
}