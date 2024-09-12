#include "main.h"

void handleMovement(SDL_Rect* player, int playerSpeed, const Uint8* keystates)
{
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


	if (mazeY < 0 || mazeX < 0 || mazeY >= mazeHeight || mazeX >= mazeWidth || maze[mazeY][mazeX] == 1) {
	if (keystates[SDL_SCANCODE_UP])
		player->y += playerSpeed;
	if (keystates[SDL_SCANCODE_DOWN])
		player->y -= playerSpeed;
	if (keystates[SDL_SCANCODE_LEFT])
		player->x += playerSpeed;
	if (keystates[SDL_SCANCODE_RIGHT])
		player->x -= playerSpeed;
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
