#pragma once

#include <cstdint>
#include <vector>
#include <memory>

struct Map;
struct Exit;

enum MapID
{
    WAKEUP = 0,
    WAKEUP_CORRIDOR,
    _TOTAL
};

struct Map
{ 
    public:
        Map(const char text[420], std::vector<Exit>&& exits) : text(text), exits(exits) {}

        const char* text;
        std::vector<Exit> exits;
};

struct Exit
{
    public:
        Exit(const MapID mapId, uint32_t exitX, uint32_t exitY, uint32_t minCornerX, uint32_t minCornerY, uint32_t maxCornerX, uint32_t maxCornerY) :
            mapId(mapId), exitX(exitX), exitY(exitY), minCornerX(minCornerX), minCornerY(minCornerY), maxCornerX(maxCornerX), maxCornerY(maxCornerY) {}

        const MapID mapId;

        const uint32_t exitX;
        const uint32_t exitY;

        const uint32_t minCornerX;
        const uint32_t minCornerY;
        const uint32_t maxCornerX;
        const uint32_t maxCornerY;

        inline bool isInside(uint32_t x, uint32_t y) const
        {
            return x >= minCornerX && y >= minCornerY && x <= maxCornerX && y <= maxCornerY;
        }
};
