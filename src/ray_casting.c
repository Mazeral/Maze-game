#include "main.h"
#include <SDL2/SDL_render.h>

/**
 * ray_casting - Handles the ray casting for rendering walls.
 * @renderer: The SDL_Renderer used for drawing.
 * @player: The SDL_Rect representing the player position.
 * @maze_width: The width of the maze.
 * @maze_height: The height of the maze.
 * @mazeCellSize: The size of each maze cell.
 * @wall_texture: The texture to use for the walls.
 * Return: The updated angle of the ray after processing input.
 */
float ray_casting(SDL_Renderer *renderer, SDL_Rect player,
		  int maze_width, int maze_height, int mazeCellSize,
		  SDL_Texture *wall_texture)
{
	float ray_angle = 0.0f, fov = 60.0f * (3.14159f / 180.0f),
	ray_angle_increment = fov / NUM_RAYS,
	initial_ray_angle = ray_angle - (fov / 2.0f),
	floor_distance = 0.0f, floor_distances[NUM_RAYS], current_angle,
	rayDistance, hitX, hitY, wall_height;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	int i, hitSide;

	/* Loop over each ray (for each pixel of the screen) */
	for (i = 0; i < NUM_RAYS; i++)
	{
		current_angle = initial_ray_angle + i * ray_angle_increment;
		/* Calculate the distance to the wall and where it was hit */
		calculate_ray_distance(current_angle,
			 player, maze_width, maze_height,
			 mazeCellSize, &rayDistance, &hitX, &hitY, &hitSide);
		/* Avoid division by zero and set a minimum value for the ray */
		if (rayDistance < 1.0f)
			rayDistance = 1.0f;  /* Smallest non-zero
			*distance to avoid division by zero
			*/
		/* Calculate the height of the wall to draw */
		wall_height = (WINDOW_HEIGHT / rayDistance) * 1.24;
		/* Limit the height of the wall to half of the upper screen */
		if (wall_height > WINDOW_HEIGHT / 1.25)
			wall_height = WINDOW_HEIGHT / 1.25;
		/* Draw the wall based on the calculated height */
		draw_wall(renderer, wall_texture, wall_height, i);
	}

	/* Update ray angle based on input */
	update_ray_angle(keystates, &ray_angle);

	return (ray_angle);
}
