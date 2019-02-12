#include <string>

class Animation
{
    public:
        Animation(std::string name, unsigned numFrames, unsigned fps);
        ~Animation();

        std::string GetName();
        unsigned GetCurrentFrame();
        void SetFPS(unsigned fps);
        
        void Update(unsigned milis);
        void Reset();
    protected:
        std::string _Name;        
        unsigned _NumFrames;
        unsigned _CurrentFrame;
        unsigned _CurrentMilis;
        unsigned _MilisPerFrame;
};