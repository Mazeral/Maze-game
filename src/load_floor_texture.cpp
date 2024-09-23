#include "main.h"

/**
 * load_floor_texture - Loads the floor texture into memory
 * @renderer: The SDL renderer to use for loading the texture
 *
 * Return: SDL_Texture* (the loaded texture) or NULL on error
 */
SDL_Texture *load_floor_texture(SDL_Renderer *renderer)
{
	SDL_Surface *floor_surface;
	SDL_Texture *floor_texture;

	/* Load floor image */
	floor_surface = IMG_Load("../depedencies/floor.bmp");
	if (!floor_surface)
	{
		printf("Error loading floor texture: %s\n", SDL_GetError());
		return (NULL);
	}

	/* Create texture from surface */
	floor_texture = SDL_CreateTextureFromSurface(renderer, floor_surface);
	SDL_FreeSurface(floor_surface);  /* Free the surface as it's no longer needed */

	if (!floor_texture)
	{
		printf("Error creating floor texture: %s\n", SDL_GetError());
	}

	return (floor_texture);
}
