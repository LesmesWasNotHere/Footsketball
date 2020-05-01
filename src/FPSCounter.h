#ifndef _FPSCOUNTER_H
#define _FPSCOUNTER_H

class FPSCounter
{
    public:
        FPSCounter();

        void Update(unsigned lastFrameMilis);

        unsigned GetFPS();
    
    private:
        const static int BUFFER_SIZE = 128;
        unsigned _Buffer[BUFFER_SIZE];
        unsigned _BufferPosition;
        unsigned _BufferSum;
};

#endif