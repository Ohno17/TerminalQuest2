#pragma once

#include <cstdio>
#include <cstdint>
#include "state.hpp"
#include "display.hpp"
#include "event.hpp"
#include "maps.hpp"

extern GameState;
extern DisplayManager;
extern EventManager;

int main(void);
void handleKeyDown(char key);
void handleResizeWindow(uint32_t columns, uint32_t rows);
