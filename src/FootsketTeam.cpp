#include "FootsketTeam.h"
#include <cassert>

FootsketTeam::FootsketTeam(const char* name):_Name(name)
{
}

const char* FootsketTeam::GetName()
{
    return _Name;
}

const std::vector<FootsketPlayer>& FootsketTeam::GetPlayers()
{
    return _Players;
}

void FootsketTeam::SetCurrentMatch(FootsketMatch& match)
{
    _CurrentMatch = &match;
}

void FootsketTeam::Update(unsigned milisFrame)
{
    assert(_CurrentMatch);

    for(std::vector<FootsketPlayer>::iterator i = _Players.begin(); i != _Players.end(); ++i)
        i->Update(milisFrame);

    unsigned distance;
    _SquareDistancePlayerNearestToBall = 0xffff;
    for(std::vector<FootsketPlayer>::iterator i = _Players.begin(); i != _Players.end(); ++i)
    {
        distance = _CurrentMatch->GetBall().GetCurrentPosition().SquareDistance((*i).GetCurrentPosition());
        if (distance < _SquareDistancePlayerNearestToBall)
        {
            _SquareDistancePlayerNearestToBall = distance;
            _PlayerNearestToBall = &(*i);
        }
    }

    assert(_PlayerNearestToBall);
}