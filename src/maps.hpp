#pragma once

#include "map.hpp"

enum MapID
{
    WAKEUP = 0,
    WAKEUP_CORRIDOR,
    TOWN,
    HOUSE,
    ALLEY,
    HOUSE_INTERIOR,
    NONE
};

extern const Map maps[MapID::NONE];
