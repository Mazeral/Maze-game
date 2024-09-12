#include "main.h"

void draw_maze(SDL_Renderer *renderer)
{
	SDL_Rect wall;

	    // Draw the maze
	    for (int y = 0; y < mazeHeight; y++) {
		for (int x = 0; x < mazeWidth; x++) {
		    if (maze[y][x] == 1) {
			wall = { x * mazeCellSize, y * mazeCellSize, mazeCellSize, mazeCellSize };
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
			SDL_RenderFillRect(renderer, &wall);
		    }
		}
	    }
}
