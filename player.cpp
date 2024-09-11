#include "main.h"

void player()
{
	/* The player position and size */
	SDL_Rect player = {100, 100, 10, 10};

	/* Render the player: */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Update the screen
	SDL_RenderPresent(renderer);
}
