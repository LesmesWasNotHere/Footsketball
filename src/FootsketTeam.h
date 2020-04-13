#ifndef _FOOTSKETTEAM_H
#define _FOOTSKETTEAM_H

#include "FootsketPlayer.h"
#include <vector>

class FootsketTeam
{
    public:
        FootsketTeam(const char* name);

        const char* GetName();

    private:
        const char* _Name;

    protected:
        std::vector<FootsketPlayer> _Players;
};

#endif