#include "main.h"

void handleMovement(SDL_Rect* player, int playerSpeed, const Uint8* keystates)
{
	int mazeX = player->x / mazeCellSize;
	int mazeY = player->y / mazeCellSize;

	int newX = player->x;
	int newY = player->y;

	if (keystates[SDL_SCANCODE_UP])
		newY -= playerSpeed;
	if (keystates[SDL_SCANCODE_DOWN])
		newY += playerSpeed;
	if (keystates[SDL_SCANCODE_LEFT])
		newX -= playerSpeed;
	if (keystates[SDL_SCANCODE_RIGHT])
		newX += playerSpeed;

	int newMazeX = newX / mazeCellSize;
	int newMazeY = newY / mazeCellSize;

	if (!(newMazeY < 0 || newMazeX < 0 || newMazeY >= mazeHeight || newMazeX >= mazeWidth || maze[newMazeY][newMazeX] == 1)) {
		player->x = newX;
		player->y = newY;
	}
}

bool isCollision(int mazeX, int mazeY)
{
	return (mazeY < mazeHeight && mazeX < mazeWidth && maze[mazeY][mazeX] == 1);
}

void move(SDL_Rect* player, int playerSpeed)
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	handleMovement(player, playerSpeed, keystates);
}
