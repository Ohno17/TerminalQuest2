#pragma once

#include <cstdint>
#include "map/map.hpp"

struct GameState
{
    public:
        GameState() { running = true; }

        bool running;

        uint32_t playerX;
        uint32_t playerY;

        Map* map;
};
