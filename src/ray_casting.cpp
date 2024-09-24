#include "main.h"
#include <SDL2/SDL_render.h>

float ray_angle = 0.0f;  // Static variable to store the current rotation angle 
float initial_ray_angle = 0.0f;
float ray_angle_increment = 0.1f;
/**
 * ray_casting - a function that handles ray casting
 * @renderer: The renderer
 * @player: The player
 * @maze_width: The width of the maze
 * @maze_height: The height of the maze
 * @mazeCellSize: The size of the maze cell
 * Return: the angle of the ray
 */
float ray_casting(SDL_Renderer *renderer, SDL_Rect player, int maze_width, int maze_height, int mazeCellSize, SDL_Texture *wall_texture)
{
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    float fov = 60.0f * (3.14159f / 180.0f);  // Field of view in radians
    float ray_angle_increment = fov / NUM_RAYS;
    float initial_ray_angle = ray_angle - (fov / 2.0f);  // Start at the leftmost edge of the FOV
	float floor_distances[NUM_RAYS];
	float floor_distance = 0.0;

    int i;

    // Loop over each ray (for each pixel of the screen)
    for (i = 0; i < NUM_RAYS; i++)
    {
        float current_angle = initial_ray_angle + i * ray_angle_increment;

        float rayDistance;
        float hitX, hitY;
        int hitSide;

        // Calculate the distance to the wall and where it was hit
        calculate_ray_distance(current_angle, player, maze_width, maze_height, mazeCellSize, &rayDistance, &hitX, &hitY, &hitSide);

        // Avoid division by zero and set a minimum value for the ray
        if (rayDistance < 1.0f)
            rayDistance = 1.0f;  // Smallest non-zero distance to avoid division by zero

        // Calculate the height of the wall to draw
        float wall_height = (WINDOW_HEIGHT / rayDistance) * 1.24;  // Simple raycasting formula

        // Limit the height of the wall to half of the upper screen
        if (wall_height > WINDOW_HEIGHT / 1.25)
            wall_height = WINDOW_HEIGHT / 1.25;

	// draw_ray(renderer, player, hitX, hitY, rayDistance);

    draw_wall(renderer, wall_texture, wall_height, i);
    }

    // Update ray angle based on input
    update_ray_angle(keystates, &ray_angle);

    return ray_angle;
}
	//
	// floor_distance = calculate_floor_distance(rayDistance, player, hitY, maze_height, mazeCellSize);
 //        floor_distances[i] = floor_distance;
