#include "main.h"

/**
 * game_running - Updates the player's position based on user input
 * @player: The SDL_Rect representing the player's position
 * @keystates: Pointer to the current keyboard state
 *
 * This function checks for user input to update the player's position
 * and determines if the player has reached the end of the map.
 *
 * Return: true if the game should continue running, false if the game
 * is over (player reached the end of the map).
 */
bool game_running(SDL_Rect *player, const Uint8 *keystates)
{
	/* Check if the player has reached the end of the map */
	if (player->x >= 18 * MAZE_CELL_SIZE && player->y >= 18 * MAZE_CELL_SIZE)
	{
		/* Game over, player has reached the end of the map */
		return (false);
	}
	return (true);
}
