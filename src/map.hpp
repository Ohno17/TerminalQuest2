#pragma once

#include <cstdint>
#include <vector>
#include <memory>

enum MapID;

struct Box;
struct Map;
struct Exit;

struct Box
{
    public:
        const int32_t minCornerX;
        const int32_t minCornerY;
        const int32_t maxCornerX;
        const int32_t maxCornerY;

        Box(const int32_t minCornerX, const int32_t minCornerY, const int32_t maxCornerX, const int32_t maxCornerY) :
            minCornerX(minCornerX), minCornerY(minCornerY), maxCornerX(maxCornerX), maxCornerY(maxCornerY) {}

        inline bool isInside(int32_t x, int32_t y) const
        {
            return x >= minCornerX && y >= minCornerY && x <= maxCornerX && y <= maxCornerY;
        }
};

struct Map
{ 
    public:
        const char* text;
        std::vector<Exit> exits;
        std::vector<Box> solids; // TODO: Add collision

        Map(const char* text, std::vector<Exit>&& exits) :
            text(text), exits(exits) {}
};

struct Exit
{
    public:
        const MapID mapId;

        const uint32_t exitX;
        const uint32_t exitY;

        const Box bounds;

        Exit(const MapID mapId, uint32_t exitX, uint32_t exitY, Box&& bounds) :
            mapId(mapId), exitX(exitX), exitY(exitY), bounds(bounds) {}
};
