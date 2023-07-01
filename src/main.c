#include "main.h"

bool initWindow(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Error : could not initialize the window !\n");
        return false;
    }

    *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_SetWindowResizable(*window, SDL_FALSE);

    if (*window == NULL)
    {
        fprintf(stderr, "Error : could not create the window !\n");
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

    if (*renderer == NULL)
    {
        fprintf(stderr, "Error : could not create the renderer !\n");
        return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Init the window
    bool success = initWindow(&window, &renderer);
    if (!success)
        return -1;

    // Init the map
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = 0;
        }
    }

    // Game loop
    gameLoop(window, renderer);

    // Quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    SDL_Quit();

    return 0;
}
