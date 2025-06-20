#include "main.hpp"

GameState state;
DisplayManager display {"Detective"};
EventManager eventManager {handleKeyDown, handleResizeWindow};

int main(void)
{
    initMaps();

    state.playerX = 10;
    state.playerY = 10;
    state.map = (Map*)WAKEUP;

    display.printGame(state);
    while (state.running) eventManager.readEvents();
}

void afterPlayerMove(void)
{
    // Check for exits
    for (std::shared_ptr<Exit> exitPtr : state.map->exits)
    {
        if ((*exitPtr).isInside(state.playerX, state.playerY))
        {
            state.playerX = (*exitPtr).exitX;
            state.playerY = (*exitPtr).exitY;
            state.map = *(*exitPtr).map;
        }
    }
    display.printMap(state);
}

void handleKeyDown(char key)
{
    switch (key)
    {
        case 0x1b:
            state.running = false;
            return;
        case 'w':
            state.playerY--;
            afterPlayerMove();
            break;
        case 's':
            state.playerY++;
            afterPlayerMove();
            break;
        case 'a':
            state.playerX--;
            afterPlayerMove();
            break;
        case 'd':
            state.playerX++;
            afterPlayerMove();
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
