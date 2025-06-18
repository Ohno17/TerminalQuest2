#pragma once

#include <cstdint>

class Map
{ 
    public:
        Map(void) {};
        Map(const char* text) : text(text) {}

        const char* text;
};
