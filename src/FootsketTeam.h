#ifndef _FOOTSKETTEAM_H
#define _FOOTSKETTEAM_H

#include "FootsketPlayer.h"
#include <vector>

class FootsketTeam
{
    public:
        FootsketTeam(const char* name, IControl& control);

        const char* GetName();

    private:
        const char* _Name;

    protected:
        IControl& _Control;
        std::vector<FootsketPlayer> _Players;
};

#endif