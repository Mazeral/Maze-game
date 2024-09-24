#include "main.h"

void handleMovement(SDL_Rect* player, int playerSpeed, const Uint8* keystates, float ray_angle)
{
	int mazeX = player->x / MAZE_CELL_SIZE;
	int mazeY = player->y / MAZE_CELL_SIZE;

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

	int newMazeX = newX / MAZE_CELL_SIZE;
	int newMazeY = newY / MAZE_CELL_SIZE;

	if (!(newMazeY < 0 || newMazeX < 0 || newMazeY >= MAZE_HEIGHT || newMazeX >= MAZE_WIDTH || maze[newMazeY][newMazeX] == 1)) {
		player->x = newX;
		player->y = newY;
	}
}

bool isCollision(int mazeX, int mazeY)
{
	return (mazeY < MAZE_HEIGHT && mazeX < MAZE_WIDTH && maze[mazeY][mazeX] == 1);
}

void move(SDL_Rect* player, int playerSpeed, float rayAngle)
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	handleMovement(player, playerSpeed, keystates, rayAngle);
}
