#include "main.hpp"

GameState state;
DisplayManager display("Detective");
EventManager eventManager(handleKeyDown, handleResizeWindow);

int main(void)
{
    state.playerX = 10;
    state.playerY = 10;
    state.map = MapID::WAKEUP;

    display.printGame(state);
    while (state.running) eventManager.readEvents();
}

void afterPlayerMove(void)
{
    // Check for exits
    for (const Exit& exit : maps[state.map].exits)
    {
        if (exit.isInside(state.playerX, state.playerY))
        {
            state.playerX = exit.exitX;
            state.playerY = exit.exitY;
            state.map = exit.mapId;
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
