#include "main.h"
#include <SDL2/SDL_rect.h>

/**
 * calculate_floor_distance - Calculate the distance to the floor
 * @current_angle: The angle of the current ray
 * @player: The player object (position and size)
 * @mazeWidth: The width of the maze in cells
 * @mazeHeight: The height of the maze in cells
 * @mazeCellSize: The size of one cell in the maze
 *
 * This function calculates the distance the ray travels before it hits the
 * floor, taking into account the player's position and the maze dimensions.
 *
 * Return: The distance to the floor
 */
float calculate_floor_distance(float current_angle, SDL_Rect player,
			       int mazeWidth, int mazeHeight, int mazeCellSize)
{
	float rayDistance = 0.0f;
	float deltaX = cos(current_angle);
	float deltaY = sin(current_angle);
	const float increment = 0.1f;  /* Larger increment for simple raycasting */
	const float max_distance = 100.0f;  /* Maximum distance */

	while (rayDistance < max_distance)
	{
		float hitX = player.x + deltaX * rayDistance;
		float hitY = player.y + deltaY * rayDistance;

		/* Check if the ray hits the floor */
		if (hitY > mazeHeight * mazeCellSize - player.y)
			break;

		rayDistance += increment;
	}

	return (rayDistance);
}
