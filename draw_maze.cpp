#include "main.h"

/** draw_maze - draws the walls of the maze
 * @renderer: The rednerer that renderers the walls
 * Return: Nothing
 */
void draw_maze(SDL_Renderer *renderer, SDL_Rect player)
{
    SDL_Rect wall;
    int x, y;

    // Draw the maze
    for (y = 0; y < mazeHeight; y++)
    {
        for (x = 0; x < mazeWidth; x++)
        {
            if (maze[y][x] == 1)
            {
                wall =
                {
                    x * mazeCellSize,
                    y * mazeCellSize,
                    mazeCellSize,
                    mazeCellSize
                };
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &wall);
            }
        }
    }

    // Draw the player
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect playerRect =
    {
        player.x,
        player.y,
        16, // Player width
        16 // Player height
    };
    SDL_RenderFillRect(renderer, &playerRect);
}
