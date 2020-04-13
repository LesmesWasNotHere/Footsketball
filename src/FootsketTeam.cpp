#include "FootsketTeam.h"

FootsketTeam::FootsketTeam(const char* name):_Name(name)
{
}

const char* FootsketTeam::GetName()
{
    return _Name;
}