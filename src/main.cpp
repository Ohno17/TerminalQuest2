#include "main.hpp"

GameState state;
DisplayManager display {"Detective"};
EventManager eventManager {handleKeyDown, handleResizeWindow};

int main(void)
{
    state.playerX = 10;
    state.playerY = 10;
    state.map.text = WAKEUP;

    display.printGame(state);
    while (state.running) eventManager.readEvents();
}

void handleKeyDown(char key)
{
    if (key == 0x1B)
    {
        state.running = false;
        return;
    }

    switch (key)
    {
        case 'w':
            state.playerY--;
            display.printMap(state);
            break;
        case 's':
            state.playerY++;
            display.printMap(state);
            break;
        case 'a':
            state.playerX--;
            display.printMap(state);
            break;
        case 'd':
            state.playerX++;
            display.printMap(state);
            break;
        default:
            break;
    }
}

void handleResizeWindow(uint32_t columns, uint32_t rows)
{
    display.clearScreen();
    display.setNewSize(columns, rows);
    display.printGame(state);
}
