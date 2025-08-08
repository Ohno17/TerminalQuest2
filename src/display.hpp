#pragma once

#include "terminal.hpp"
#include "state.hpp"
#include "maps.hpp"
#include <cstdio>
#include <cstdint>

class DisplayManager : public TerminalBuffer
{
    private:
        static const uint32_t mapBoxInnerX = 4;
        static const uint32_t mapBoxInnerY = 3;
        static const uint32_t textBoxInnerX = 27;
        static const uint32_t textBoxInnerY = 3;
    public:
        DisplayManager(const char* title) : TerminalBuffer(title) {}

        void printGame(GameState& state);
        void printMap(GameState& state);

        void printText(uint32_t x, uint32_t y, const char* text);
        void printTextWithWrap(uint32_t x, uint32_t y, const char* text, uint32_t wrapLimit);
        void printBox(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
};
