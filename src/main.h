#include <stdbool.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "render.h"

#ifndef MAIN_H
#define MAIN_H

extern int map[MAP_HEIGHT][MAP_WIDTH];

bool initWindow(SDL_Window **window, SDL_Renderer **renderer);

#endif
