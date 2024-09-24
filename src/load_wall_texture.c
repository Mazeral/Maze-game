#include "main.h"

/**
 * load_wall_texture - Loads the wall texture from an image file
 * @renderer: The SDL renderer to create the texture
 * @file_path: Path to the image file for the wall texture
 *
 * Return: A pointer to the loaded SDL_Texture, or NULL on failure
 */
SDL_Texture *load_wall_texture(SDL_Renderer *renderer, const char *file_path)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	/* Load the image into a surface */
	surface = IMG_Load(file_path);
	if (!surface)
	{
		printf("Error loading texture: %s\n", IMG_GetError());
		return (NULL);
	}

	/* Create texture from surface */
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);  /* Free the surface as it's no longer needed */

	if (!texture)
	{
		printf("Error creating texture: %s\n", SDL_GetError());
	}

	return (texture);
}
