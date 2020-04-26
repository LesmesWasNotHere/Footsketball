#ifndef _FOOTSKETMATCH_H
#define _FOOTSKETMATCH_H

#include "FootsketTeam.h"
#include "FootsketBall.h"

class FootsketTeam;

class FootsketMatch 
{
    public:
        FootsketMatch(FootsketTeam& homeTeam, FootsketTeam& awayTeam, FootsketBall& ball);

        void StartMatch();

        FootsketTeam& GetHomeTeam();
        FootsketTeam& GetAwayTeam();

        FootsketBall& GetBall();

        unsigned GetCurrentTime();
        unsigned GetHomeTeamScore();
        unsigned GetAwayTeamScore();

        void Update(unsigned milisFrame);
    private:
        unsigned _HomeTeamScore;
        unsigned _AwayTeamScore;
        bool _SecondHalve;
        unsigned _CurrentTime;

        FootsketTeam& _HomeTeam;
        FootsketTeam& _AwayTeam;
        FootsketBall& _Ball;
};

#endif