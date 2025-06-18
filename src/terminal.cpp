#include "terminal.hpp"

// Initalizes alternate terminal buffer
TerminalBuffer::TerminalBuffer(const char* title)
{
    printf("\x1b[?1049h");
    printf("\x1b[?25l");
    setCursorPosition(1, 1);
    printf("\x1b]0;%s\x1b\x5c", title);

    calculateDimensions();

    SetConsoleOutputCP(CP_UTF8);
}

// Reverts to main terminal buffer
TerminalBuffer::~TerminalBuffer(void)
{
    printf("\x1b[?1049l");
    printf("\x1b[?25h");
}

// Calculates and stores dimensions of terminal
void TerminalBuffer::calculateDimensions(void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    this->columns = info.srWindow.Right - info.srWindow.Left + 1;
    this->rows = info.srWindow.Bottom - info.srWindow.Top + 1;
}

// Set new known size
void TerminalBuffer::setNewSize(uint32_t columns, uint32_t rows)
{
    this->columns = columns;
    this->rows = rows;
}

// Returns the terminal rows
unsigned int TerminalBuffer::getNumRows(void)
{
    return this->rows;
}

// Returns the terminal columns
unsigned int TerminalBuffer::getNumColumns(void)
{
    return this->columns;
}

// Sets text format for new text
void TerminalBuffer::setTextFormat(FormatFlags format)
{
    printf("\x1b[%dm", format);
}

// Sets the cursor position, with 1:1 at top left
void TerminalBuffer::setCursorPosition(uint32_t x, uint32_t y)
{
    printf("\x1b[%d;%dH", y, x);
}

// Clears the buffer
void TerminalBuffer::clearScreen(void)
{
    printf("\x1b[2J");
}
