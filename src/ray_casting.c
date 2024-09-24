#include "main.h"
#include <SDL2/SDL_render.h>

/**
 * calculate_ray_distance - a function to calculate the distance to the wall
 * @current_angle: The current angle of the ray
 * @player: The player position
 * @mazeCellSize: The size of the maze cell
 * @rayDistance: The distance to the wall
 * @hitX: The x position of the hit
 * @hitY: The y position of the hit
 * @hitSide: The side of the hit (0 for x, 1 for y)
 * Return: Nothing
 */
void calculate_ray_distance(float current_angle, SDL_Rect player,
			    int mazeCellSize, float *rayDistance,
			    float *hitX, float *hitY, int *hitSide)
{
	*rayDistance = 0.0f;
	float deltaX = cos(current_angle);
	float deltaY = sin(current_angle);

	const float increment = 0.1f;
	const float max_distance = 100.0f;

	while (*rayDistance < max_distance)
	{
		*hitX = player.x + deltaX * *rayDistance;
		*hitY = player.y + deltaY * *rayDistance;

		int wallX = (int)(*hitX) / mazeCellSize;
		int wallY = (int)(*hitY) / mazeCellSize;

		if (isWall(wallX, wallY))
		{
			*hitSide = (fabs(*hitX - wallX * mazeCellSize)
				< fabs(*hitY - wallY * mazeCellSize)) ? 0 : 1;
			break;
		}

		*rayDistance += increment;
	}
}
/**
 * ray_casting - Handles the ray casting for rendering walls.
 * @renderer: The SDL_Renderer used for drawing.
 * @player: The SDL_Rect representing the player position.
 * @mazeCellSize: The size of each maze cell.
 * @wall_texture: The texture to use for the walls.
 * @ray_angle: The angle of the rays
 * Return: The updated angle of the ray after processing input.
 */
void ray_casting(SDL_Renderer *renderer, SDL_Rect player,
		SDL_Texture *wall_texture,
		float *ray_angle)
{
	float fov = 60.0f * (3.14159f / 180.0f),
	ray_angle_increment = fov / NUM_RAYS,
	initial_ray_angle = *ray_angle - (fov / 2.0f), current_angle,
	rayDistance, hitX, hitY, wall_height;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	int i, hitSide;

	/* Loop over each ray (for each pixel of the screen) */
	for (i = 0; i < NUM_RAYS; i++)
	{
		current_angle = initial_ray_angle + i * ray_angle_increment;
		/* Calculate the distance to the wall and where it was hit */
		calculate_ray_distance(current_angle, player,
				    (int)MAZE_CELL_SIZE, &rayDistance,
				    &hitX, &hitY, &hitSide);
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
	*ray_angle = update_ray_angle(keystates, *ray_angle);
}
