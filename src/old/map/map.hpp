#pragma once

#include <cstdint>
#include <vector>
#include <memory>

class Map;
class Exit;

class Map
{ 
    public:
        Map(const char* text, std::vector<std::shared_ptr<Exit>> &exits) : text(text), exits(exits) {}

        const char* text;
        std::vector<std::shared_ptr<Exit>> exits;
};

struct Exit
{
    public:
        Exit(Map** map, uint32_t exitX, uint32_t exitY, uint32_t minCornerX, uint32_t minCornerY, uint32_t maxCornerX, uint32_t maxCornerY) :
            map(map), exitX(exitX), exitY(exitY), minCornerX(minCornerX), minCornerY(minCornerY), maxCornerX(maxCornerX), maxCornerY(maxCornerY) {}

        Map** map;

        const uint32_t exitX;
        const uint32_t exitY;

        const uint32_t minCornerX;
        const uint32_t minCornerY;
        const uint32_t maxCornerX;
        const uint32_t maxCornerY;

        bool isInside(uint32_t x, uint32_t y) const
        {
            return x >= minCornerX && y >= minCornerY && x <= maxCornerX && y <= maxCornerY;
        }
};
