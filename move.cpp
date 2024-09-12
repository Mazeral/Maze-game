#include "main.h"

void move(SDL_Rect* player, int playerSpeed)
{
	/*Gets the input*/
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	/*These lines calculate the coordinates of the player within the maze. The mazeCellSize variable represents the size of each cell in the maze. By dividing the player's x and y coordinates by mazeCellSize, the code determines which cell in the maze the player is currently occupying.
	 * This works because When you divide the player's position by the cell size, you're essentially converting the player's position from pixel coordinates to tile coordinates.*/
	int mazeX = player->x / mazeCellSize;
	int mazeY = player->y / mazeCellSize;

	if (keystates[SDL_SCANCODE_UP])
		player->y -= playerSpeed;
	if (keystates[SDL_SCANCODE_DOWN]) 
		player->y += playerSpeed;
	if (keystates[SDL_SCANCODE_LEFT])
		player->x -= playerSpeed;
	if (keystates[SDL_SCANCODE_RIGHT])
		player->x += playerSpeed;

	/* Check for collisions with the maze */ 
	if (mazeY < mazeHeight && mazeX < mazeWidth && maze[mazeY][mazeX] == 1)
	{
		// If the player collides with a wall, move them back
	// Before moving the player
	if (keystates[SDL_SCANCODE_UP])
		if (mazeY - 1 >= 0 && maze[mazeY - 1][mazeX] != 1)
			player->y -= playerSpeed;

	if (keystates[SDL_SCANCODE_DOWN])
		if (mazeY + 1 < mazeHeight && maze[mazeY + 1][mazeX] != 1)
			player->y += playerSpeed;

	if (keystates[SDL_SCANCODE_LEFT])
	    if (mazeX - 1 >= 0 && maze[mazeY][mazeX - 1] != 1)
		player->x -= playerSpeed;

	if (keystates[SDL_SCANCODE_RIGHT])
	    if (mazeX + 1 < mazeWidth && maze[mazeY][mazeX + 1] != 1)
		player->x += playerSpeed;
	}
}
