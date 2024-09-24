#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>

/**
 * draw_floor - Renders the floor texture for each ray in the scene
 * @renderer: Pointer to the SDL renderer
 * @floor_texture: Pointer to the SDL texture for the floor
 * @player: SDL_Rect structure representing the player
 *
 * This function calculates the distance for each ray and renders the floor
 * texture accordingly for each ray. It ensures that the floor texture is
 * drawn to fill the lower half of the screen.
 */
void draw_floor(SDL_Renderer *renderer,
		SDL_Texture *floor_texture,
		SDL_Rect player)
{
	int i;
	float current_angle, rayDistance, hitX, hitY;
	int hitSide;
	SDL_Rect floor_rect;

	for (i = 0; i < NUM_RAYS; i++)
	{
		current_angle = (i - NUM_RAYS / 2.0) * (3.14159f / 180.0f);

	calculate_ray_distance(current_angle, player,
				    MAZE_CELL_SIZE, &rayDistance,
				    &hitX, &hitY, &hitSide);

		/* Define the rectangle to render the floor texture */
		floor_rect.x = i * WINDOW_WIDTH / NUM_RAYS;
		floor_rect.y = WINDOW_HEIGHT / 2;
		floor_rect.w = WINDOW_WIDTH / NUM_RAYS;
		floor_rect.h = WINDOW_HEIGHT / 2;

		/* Render the floor texture */
		SDL_RenderCopy(renderer, floor_texture, NULL, &floor_rect);
	}
}
