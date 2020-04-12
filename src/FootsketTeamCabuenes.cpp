#include "FootsketTeamCabuenes.h"

FootsketTeamCabuenes::FootsketTeamCabuenes(IControl& control):FootsketTeam("Cabueñes", control)
{
    InitPlayers();
}

void FootsketTeamCabuenes::InitPlayers()
{
    _Players.push_back(FootsketPlayer("Hugo", "CAB_HUGO", _Control));
    _Players.push_back(FootsketPlayer("Pedro", "CAB_HUGO", _Control));
    _Players.push_back(FootsketPlayer("Juan Luís", "CAB_HUGO", _Control));
}