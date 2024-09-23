#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
/**
 * draw_sky - Draws the sky texture at the top of the screen
 * @renderer: The SDL renderer
 * @sky_texture: The loaded sky texture to render
 *
 * Return: void
 */
void draw_sky(SDL_Renderer *renderer, SDL_Texture *sky_texture)
{
	/* y=240 and height=240, so it covers half of the screen */
	SDL_Rect sky_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

	/* Copy the sky texture to the renderer */
	if (SDL_RenderCopy(renderer, sky_texture, NULL, &sky_rect) != 0)
	{
		printf("SDL_RenderCopy Error: %s\n", SDL_GetError());
	}
}
