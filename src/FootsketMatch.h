#ifndef _FOOTSKETMATCH_H
#define _FOOTSKETMATCH_H

#include "FootsketTeam.h"

class FootsketMatch 
{
    public:
        void StartMatch();
    private:
        unsigned _ScoreHomeTeam;
        unsigned _ScoreAwayTeam;
        bool _SecondHalve;
        unsigned _CurrentTime;

        FootsketTeam& _HomeTeam;
        FootsketTeam& _AwayTeam;
};

#endif