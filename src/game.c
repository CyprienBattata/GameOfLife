#include "game.h"

int map[MAP_HEIGHT][MAP_WIDTH];

int countNeighbours(int map[MAP_HEIGHT][MAP_WIDTH], int row, int col)
{
    int neighboursCount = 0;
    int possibilities[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    for (int i = 0; i < 8; i++)
    {
        int neighbourRow = row + possibilities[i][0];
        int neighbourCol = col + possibilities[i][1];

        // Verify is the index is still on the map
        if (neighbourRow < 0 || neighbourCol < 0 || neighbourRow >= MAP_HEIGHT || neighbourCol >= MAP_WIDTH)
            continue;

        neighboursCount += map[neighbourRow][neighbourCol];
    }

    return neighboursCount;
}

void nextTurn(int map[MAP_HEIGHT][MAP_WIDTH])
{
    int newMap[MAP_HEIGHT][MAP_WIDTH] = {{0}};

    // Compute alterations
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            int neighbours = countNeighbours(map, i, j);
            int currentCell = map[i][j];

            if (currentCell == 0 && neighbours == 3)
            {
                newMap[i][j] = 1;
            }
            else if (currentCell == 1)
            {
                if (2 <= neighbours && neighbours <= 3)
                {
                    newMap[i][j] = 1;
                }
                else
                {
                    newMap[i][j] = 0;
                }
            }
        }
    }

    // Copy alterations into the map
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = newMap[i][j];
        }
    }
}
