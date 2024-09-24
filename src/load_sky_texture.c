#include "main.h"
/**
 * load_sky_texture - Loads the sky texture into memory
 * @renderer: The SDL renderer to use for loading the texture
 *
 * Return: SDL_Texture* (the loaded texture) or NULL on error
 */
SDL_Texture *load_sky_texture(SDL_Renderer *renderer)
{
	SDL_Surface *sky_surface;
	SDL_Texture *sky_texture;

	/* Load sky image */
	sky_surface = IMG_Load("../depedencies/sky.bmp");
	if (!sky_surface)
	{
		printf("Error loading sky texture: %s\n", IMG_GetError());
		return (NULL);
	}

	/* Create texture from surface */
	sky_texture = SDL_CreateTextureFromSurface(renderer, sky_surface);
	SDL_FreeSurface(sky_surface);  /* Free the surface as it's no longer needed */

	if (!sky_texture)
	{
		printf("Error creating sky texture: %s\n", SDL_GetError());
	}

	return (sky_texture);
}
