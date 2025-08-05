#include "event.hpp"

// Initalize terminal for instant keys
EventManager::EventManager(KeyEventHandler* keyHandler, ResizeEventHandler* resizeHandler)
{
    this->keyHandler = keyHandler;
    this->resizeHandler = resizeHandler;
    this->stdIn = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(stdIn, &(this->oldInputMode));
    SetConsoleMode(stdIn, ENABLE_WINDOW_INPUT);
}

// Reset terminal input mode
EventManager::~EventManager()
{
    SetConsoleMode(stdIn, this->oldInputMode);
}

// Read new events for key events
void EventManager::readEvents(void)
{
    ReadConsoleInput(this->stdIn, this->eventBuffer, 64, &(this->eventsRead));

    bool alreadyResized = false;
    for (uint32_t i = 0; i < this->eventsRead; i++)
    {
        switch (this->eventBuffer[i].EventType)
        {
            case KEY_EVENT:
                KEY_EVENT_RECORD keyRecord = this->eventBuffer[i].Event.KeyEvent;
                if(keyRecord.bKeyDown) this->keyHandler(keyRecord.uChar.AsciiChar);
                break;
            case WINDOW_BUFFER_SIZE_EVENT:
                if (alreadyResized) break;
                
                alreadyResized = true;
                WINDOW_BUFFER_SIZE_RECORD windowRecord = this->eventBuffer[i].Event.WindowBufferSizeEvent;
                this->resizeHandler(windowRecord.dwSize.X, windowRecord.dwSize.Y);
                break;
            default:
                break;
        }
    }
}