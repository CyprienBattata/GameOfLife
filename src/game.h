#include <SDL2/SDL.h>

#ifndef GAME_H
#define GAME_H

#define MAP_WIDTH 50
#define MAP_HEIGHT 50

void nextTurn(int map[MAP_HEIGHT][MAP_WIDTH]);
int countNeighbours(int map[MAP_HEIGHT][MAP_WIDTH], int x, int y);

#endif
