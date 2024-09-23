#include "main.h"

bool game_running(SDL_Rect player, const Uint8* keystates)
{
    // Update the player's position based on user input
    if (keystates[SDL_SCANCODE_UP]) {
        player.y -= 10;
    } else if (keystates[SDL_SCANCODE_DOWN]) {
        player.y += 10;
    } else if (keystates[SDL_SCANCODE_LEFT]) {
        player.x -= 10;
    } else if (keystates[SDL_SCANCODE_RIGHT]) {
        player.x += 10;
    }

    // Check if the player has reached the end of the map
    if (player.x >= 18 * mazeCellSize && player.y >= 18 * mazeCellSize) {
        // Game over, player has reached the end of the map
	return false;
    }
    return true;
}
