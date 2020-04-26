#include "FootsketMatch.h"

FootsketMatch::FootsketMatch(FootsketTeam& homeTeam, FootsketTeam& awayTeam, FootsketBall& ball):_HomeTeam(homeTeam), _AwayTeam(awayTeam), _Ball(ball)
{
    _HomeTeam.SetCurrentMatch(*this);
    _AwayTeam.SetCurrentMatch(*this);
}

void FootsketMatch::StartMatch()
{
    _SecondHalve = false;
    _HomeTeamScore = _AwayTeamScore = _CurrentTime = 0;
}

FootsketTeam& FootsketMatch::GetHomeTeam()
{
    return _HomeTeam;
}

FootsketTeam& FootsketMatch::GetAwayTeam()
{
    return _AwayTeam;
}

FootsketBall& FootsketMatch::GetBall()
{
    return _Ball;
}

unsigned FootsketMatch::GetCurrentTime()
{
    return _CurrentTime;
}

unsigned FootsketMatch::GetHomeTeamScore()
{
    return _HomeTeamScore;
}

unsigned FootsketMatch::GetAwayTeamScore()
{
    return _AwayTeamScore;
}

void FootsketMatch::Update(unsigned milisFrame)
{
    unsigned distance;

    _CurrentTime += milisFrame;

    _HomeTeam.Update(milisFrame);
    _AwayTeam.Update(milisFrame);
    
    _Ball.Update(milisFrame);
}
