#pragma once

#include <Windows.h>
#include <cstdint>
#include <cstdio>

typedef void (KeyEventHandler)(char key);
typedef void (ResizeEventHandler)(uint32_t columns, uint32_t rows);

class EventManager
{
    private:
        HANDLE stdIn;
        DWORD oldInputMode;
        DWORD eventsRead;
        INPUT_RECORD eventBuffer[64];

        KeyEventHandler* keyHandler;
        ResizeEventHandler* resizeHandler;
    public:
        EventManager(KeyEventHandler* keyHandler, ResizeEventHandler* resizeHandler);
        ~EventManager();

        void readEvents(void);
};
