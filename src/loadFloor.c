#include "main.h"
/**
 * loadFloor - Loads the floor texture from a BMP file
 * @renderer: The SDL renderer to create the texture
 *
 * Return: A pointer to the loaded SDL_Texture, or NULL on failure
 */
SDL_Texture *loadFloor(SDL_Renderer *renderer)
{
	SDL_Surface *floorSurface;
	SDL_Texture *floorTexture;

	/* Load the BMP image into a surface */
	floorSurface = SDL_LoadBMP("../depedencies/floor.bmp");
	if (floorSurface == NULL)
	{
		printf("Error loading floor texture: %s\n", SDL_GetError());
		return (NULL);
	}

	/* Create texture from the surface */
	floorTexture = SDL_CreateTextureFromSurface(renderer, floorSurface);
	if (floorTexture == NULL)
	{
		printf("Error creating floor texture: %s\n", SDL_GetError());
		SDL_FreeSurface(floorSurface);
		return (NULL);
	}

	SDL_FreeSurface(floorSurface);  /*Free the surface as it's no longer needed*/
	return (floorTexture);
}
