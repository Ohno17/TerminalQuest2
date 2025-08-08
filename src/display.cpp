#include "display.hpp"

// Prints all game elements
void DisplayManager::printGame(GameState& state)
{
    printMap(state);

    // Print borders
    setTextFormat(RED);
    printBox(1, 1, getNumColumns(), getNumRows());
    printBox(3, 2, textBoxInnerX - 3, 23);
    printBox(textBoxInnerX - 1, 2, getNumColumns() - 2, getNumRows() - 1);
    printText((getNumColumns() / 2) - 5, 1, "Detective");

    setTextFormat(YELLOW);
    setCursorPosition(textBoxInnerX, getNumRows() - 2);
    printf("Rows: %d, Cols: %d, ESC to terminate", getNumRows(), getNumColumns());

    setTextFormat(YELLOW);
    printText(textBoxInnerX, textBoxInnerY, "Detective:");
    setTextFormat(WHITE);
    printTextWithWrap(textBoxInnerX, textBoxInnerY + 1, "The quick brown fox jumps over the lazy dog. Lorem ipsum dolor sit amet,consectetur adipiscing elit. To be or not to be, that is the question. All that glitters is not gold. A journey of a thousand miles begins with a single step. This is just a long string used as a sample text in C programming.", getNumColumns() - 10);
}

// Prints text at position
void DisplayManager::printText(uint32_t x, uint32_t y, const char* text)
{
    setCursorPosition(x, y);
    printf(text);
}

// Prints text at position with a wrap limit, breaking text at spaces
void DisplayManager::printTextWithWrap(uint32_t x, uint32_t y, const char* text, uint32_t wrapLimit)
{
    setCursorPosition(x, y);
    
    uint32_t current = 0;
    uint32_t start = 0;
    uint32_t currentY = y;
    uint32_t currentX = x;
    for (; text[current] != '\0'; current++)
    {
        if (currentX >= wrapLimit)
        {
            currentX = x;
            setCursorPosition(x, ++currentY);
        }
        if (text[current] == ' ')
        {
            printf("%.*s", current - start, text + start);
            start = current;
        }
        currentX++;
    }
    printf("%.*s", current - start, text + start);
}

// Prints map text
void DisplayManager::printMap(GameState& state)
{
    setTextFormat(GREEN);
    setCursorPosition(mapBoxInnerX, mapBoxInnerY);

    uint32_t currentX = 0;
    uint32_t currentY = 0;
    for (uint32_t i = 0; maps[state.map].text[i] != '\0'; i++)
    {
        if (maps[state.map].text[i] == '\n')
        {
            currentX = 0;
            currentY++;
            setCursorPosition(mapBoxInnerX, mapBoxInnerY + currentY);
            continue;
        }
        currentX++;

        if (state.playerX == currentX && currentY == state.playerY)
        {
            setTextFormat(RED);
            printf("@");
            setTextFormat(GREEN);
        }
        else printf("%c", maps[state.map].text[i]);
    }
}

// Prints border box
void DisplayManager::printBox(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
    setCursorPosition(x1, y1);
    printf("╔");
    setCursorPosition(x2, y1);
    printf("╗");
    setCursorPosition(x1, y2);
    printf("╚");
    setCursorPosition(x2, y2);
    printf("╝");

    for (uint32_t x = x1 + 1; x < x2; x++)
    {
        setCursorPosition(x, y1);
        printf("═");
        setCursorPosition(x, y2);
        printf("═");
    }

    for (uint32_t y = y1 + 1; y < y2; y++)
    {
        setCursorPosition(x1, y);
        printf("║");
        setCursorPosition(x2, y);
        printf("║");
    }
}
