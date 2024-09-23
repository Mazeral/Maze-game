#include "main.h"

void handleMovement(SDL_Rect* player, int playerSpeed, const Uint8* keystates, float rayAngle)
{
	int mazeX = player->x / mazeCellSize;
	int mazeY = player->y / mazeCellSize;

	int newX = player->x;
	int newY = player->y;

	if (keystates[SDL_SCANCODE_UP])
	{
		// Move forward towards the ray casted
		newX += cos(rayAngle) * playerSpeed;
		newY += sin(rayAngle) * playerSpeed;
	}

	if (keystates[SDL_SCANCODE_DOWN])
	{
		// Move backward towards the ray casted
		newX -= cos(rayAngle) * playerSpeed;
		newY -= sin(rayAngle) * playerSpeed;
	}

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

void move(SDL_Rect* player, int playerSpeed, float rayAngle)
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	handleMovement(player, playerSpeed, keystates, rayAngle);
}
