#include "FootsketTeam.h"

FootsketTeam::FootsketTeam(const char* name, IControl& control):_Name(name), _Control(control)
{
}

const char* FootsketTeam::GetName()
{
    return _Name;
}