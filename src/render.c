#include "render.h"

void gameLoop(SDL_Window *window, SDL_Renderer *renderer)
{
    // Event loop
    SDL_Event event;
    bool quit = false;

    int cellWidth = SCREEN_WIDTH / MAP_WIDTH;
    int cellHeight = SCREEN_HEIGHT / MAP_HEIGHT;

    int delay = 150;
    bool paused = true;

    while (!quit)
    {
        // Event loop
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                // Pause
                case SDLK_SPACE:
                    paused = !paused;
                    break;
                // Go [f]aster
                case SDLK_f:
                    delay -= 10;
                    break;
                // Go [s]lower
                case SDLK_s:
                    delay += 10;
                    break;
                }
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                // Get cell's coord
                int cellRow = floor(event.button.y / cellHeight);
                int cellCol = floor(event.button.x / cellWidth);

                // Inverse cell's state
                if (map[cellRow][cellCol] == 1)
                {
                    map[cellRow][cellCol] = 0;
                }
                else
                {
                    map[cellRow][cellCol] = 1;
                }
            }
        }

        // Rendering
        render(window, renderer, cellWidth, cellHeight);

        // Computing next turn
        if (!paused)
            nextTurn(map);

        SDL_Delay(delay);
    }
}

void render(SDL_Window *window, SDL_Renderer *renderer, int cellWidth, int cellHeight)
{
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Draw cells
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            if (map[i][j] == 1)
            {
                SDL_Rect cell = {
                    .x = j * cellWidth,
                    .y = i * cellHeight,
                    .w = cellWidth,
                    .h = cellHeight};
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }

    // Draw outlines
    SDL_SetRenderDrawColor(renderer, 0x80, 0x80, 0x80, SDL_ALPHA_OPAQUE);

    // Vertical
    for (int i = 1; i < MAP_WIDTH; i++)
    {
        SDL_RenderDrawLine(renderer, i * cellWidth, 0, i * cellWidth, SCREEN_HEIGHT);
    }

    // Horizontal
    for (int i = 1; i < MAP_HEIGHT; i++)
    {
        SDL_RenderDrawLine(renderer, 0, i * cellHeight, SCREEN_WIDTH, i * cellHeight);
    }

    // Update Screen
    SDL_RenderPresent(renderer);
}
