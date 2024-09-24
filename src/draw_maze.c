#include "main.h"

/**
 * draw_maze - Draws the walls of the maze and the player
 * @renderer: The SDL renderer used for rendering the maze walls
 * @player: SDL_Rect structure representing the player
 *
 * This function iterates through the maze grid and draws the walls in black.
 * It also renders the player as a black rectangle.
 *
 * Return: Nothing
 */
void draw_maze(SDL_Renderer *renderer, SDL_Rect player)
{
	SDL_Rect wall;
	SDL_Rect playerRect;
	int x, y;
	const int maze[MAZE_WIDTH][MAZE_HEIGHT] = MAZE;

	/* Draw the maze */
	for (y = 0; y < MAZE_HEIGHT; y++)
	{
		for (x = 0; x < MAZE_WIDTH; x++)
		{
			if (maze[y][x] == 1)
			{
				wall.x = x * MAZE_CELL_SIZE;
				wall.y = y * MAZE_CELL_SIZE;
				wall.w = MAZE_CELL_SIZE;
				wall.h = MAZE_CELL_SIZE;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderFillRect(renderer, &wall);
			}
		}
	}

	/* Draw the player */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	playerRect.x = player.x;
	playerRect.y = player.y;
	playerRect.w = 16; /* Player width */
	playerRect.h = 16; /* Player height */
	SDL_RenderFillRect(renderer, &playerRect);
}
