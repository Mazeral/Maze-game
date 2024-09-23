#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>

void draw_floor(SDL_Renderer *renderer, SDL_Texture *floor_texture, SDL_Rect player)
{
    for (int i = 0; i < NUM_RAYS; i++)
    {
        float current_angle = (i - NUM_RAYS / 2.0) * (3.14159f / 180.0f);
        float rayDistance;
        float hitX;
        float hitY;
        int hitSide;

        calculate_ray_distance(current_angle, player, mazeWidth, mazeHeight, mazeCellSize, &rayDistance, &hitX, &hitY, &hitSide);
	// printf("Current ray distance for wall %f\n", rayDistance);

        // Render the floor texture for each ray
        SDL_Rect floor_rect =
	{
	    i * WINDOW_WIDTH / NUM_RAYS,
	    WINDOW_HEIGHT / 2,
	    WINDOW_WIDTH / NUM_RAYS,
	    WINDOW_HEIGHT / 2
	};
        SDL_RenderCopy(renderer, floor_texture, NULL, &floor_rect);
    }
}
