#ifndef _FOOTSKETTEAM_H
#define _FOOTSKETTEAM_H

#include "FootsketPlayer.h"
#include "FootsketMatch.h"
#include <vector>
#include <functional>

class FootsketMatch;

class FootsketTeam
{
    public:
        FootsketTeam(const char* name);

        const char* GetName();

        void SetCurrentMatch(FootsketMatch& match);
        const std::vector<FootsketPlayer>& GetPlayers();

        void Update(unsigned milisFrame);
    private:
        const char* _Name;

    protected:
        std::vector<FootsketPlayer> _Players;
        FootsketPlayer* _PlayerNearestToBall;
        double _SquareDistancePlayerNearestToBall;
        FootsketMatch* _CurrentMatch; 
};

#endif