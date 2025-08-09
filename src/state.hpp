#pragma once

#include <cstdint>
#include "maps.hpp"

struct GameState
{
    public:
        GameState() : running(true) {}

        bool running;

        int32_t playerX;
        int32_t playerY;

        MapID map = MapID::NONE;
};
