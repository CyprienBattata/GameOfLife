#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "game.h"

#ifndef RENDER_H
#define RENDER_H

extern int map[MAP_HEIGHT][MAP_WIDTH];

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

void gameLoop(SDL_Window *window, SDL_Renderer *renderer);
void render(SDL_Window *window, SDL_Renderer *renderer, int cellWidth, int cellHeight);

#endif
