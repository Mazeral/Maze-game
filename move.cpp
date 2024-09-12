#include "main.h"

void move(SDL_Rect* player, int playerSpeed)
{
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP]) {
        player->y -= playerSpeed;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        player->y += playerSpeed;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        player->x -= playerSpeed;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        player->x += playerSpeed;
    }

    // Check for collisions with the maze
    int mazeX = player.x / mazeCellSize;
    int mazeY = player.y / mazeCellSize;
    if (mazeY < mazeHeight && mazeX < mazeWidth && maze[mazeY][mazeX] == 1) {
	// If the player collides with a wall, move them back
	if (keystates[SDL_SCANCODE_UP]) {
	    player.y += playerSpeed;
	}
	if (keystates[SDL_SCANCODE_DOWN]) {
	    player.y -= playerSpeed;
	}
	if (keystates[SDL_SCANCODE_LEFT]) {
	    player.x += playerSpeed;
	}
	if (keystates[SDL_SCANCODE_RIGHT]) {
	    player.x -= playerSpeed;
	}
    }
}
