#pragma once

#include <Windows.h>
#include <cstdint>
#include <cstdio>

enum FormatFlags
{
    DEFAULT = 0,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37
};

class TerminalBuffer
{
    private:
        unsigned int rows;
        unsigned int columns;
    public:
        TerminalBuffer(const char* title);
        ~TerminalBuffer(void);

        void calculateDimensions(void);
        void setNewSize(uint32_t columns, uint32_t rows);
        unsigned int getNumRows(void);
        unsigned int getNumColumns(void);

        void setTextFormat(FormatFlags format);
        void setCursorPosition(uint32_t x, uint32_t y);

        void clearScreen(void);
};
