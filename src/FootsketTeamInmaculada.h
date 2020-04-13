#ifndef _FOOTSKETPLAYERINMACULADA_H
#define _FOOTSKETPLAYERINMACULADA_H

#include "FootsketTeam.h"
#include "IControl.h"

class FootsketTeamInmaculada: public FootsketTeam
{
    public:
        FootsketTeamInmaculada();

    protected:
        void InitPlayers();
}; 

#endif