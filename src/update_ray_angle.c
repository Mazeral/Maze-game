#include "main.h"
/**
 * update_ray_angle - Update the ray angle based on player input.
 * @keystates: The current keyboard state.
 * @ray_angle: Pointer to the player's current ray angle.
 *
 * Description: This function adjusts the player's ray angle based on
 * keyboard input. If the left arrow is pressed, the ray angle decreases,
 * simulating a left rotation. If the right arrow is pressed, the ray angle
 * increases, simulating a right rotation. The angle is wrapped to stay
 * within the range of 0 to 2π.
 */
float update_ray_angle(const Uint8 *keystates, float ray_angle)
{
	float rotation_speed = 0.05f;  /* Adjust rotation speed as needed */

	if (keystates[SDL_SCANCODE_LEFT])
	{
		ray_angle -= rotation_speed;
		if (ray_angle < 0)
		{
			ray_angle += 2 * M_PI;  /* Wrap around */
		}
	}

	if (keystates[SDL_SCANCODE_RIGHT])
	{
		ray_angle += rotation_speed;
		if (ray_angle >= 2 * M_PI)
		{
			ray_angle -= 2 * M_PI;  /* Wrap around */
		}
	}
	return (ray_angle);
}
