#ifndef _FOOTSKETPLAYERCABUENES_H
#define _FOOTSKETPLAYERCABUENES_H

#include "FootsketTeam.h"
#include "IControl.h"

class FootsketTeamCabuenes: public FootsketTeam
{
    public:
        FootsketTeamCabuenes(IControl& control);

    protected:
        void InitPlayers();
};

#endif