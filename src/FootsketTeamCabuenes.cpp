#include "FootsketTeamCabuenes.h"

FootsketTeamCabuenes::FootsketTeamCabuenes():FootsketTeam("Cabueñes")
{
    InitPlayers();
}

void FootsketTeamCabuenes::InitPlayers()
{
    _Players.push_back(FootsketPlayer("Hugo", "CAB_HUGO"));
    _Players.push_back(FootsketPlayer("Pedro", "CAB_HUGO"));
    _Players.push_back(FootsketPlayer("Juan Luís", "CAB_HUGO"));
}