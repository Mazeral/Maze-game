#include "main.h"
/**
 * loadFloor - loads the floor from a BMP NOT WORKING!!!
 * @renderer: The renderer of SDL
 * Return: Texture of the floor
 */
SDL_Texture* loadFloor(SDL_Renderer* renderer)
{
	SDL_Surface* floorSurface = SDL_LoadBMP("../depedencies/floor.bmp");
	SDL_Texture* floorTexture = SDL_CreateTextureFromSurface(renderer, floorSurface);
	if (floorSurface == NULL)
	{
		printf("Error loading floor texture: %s\n", SDL_GetError());
		return (NULL);
	}

	if (floorTexture == NULL)
	{
		printf("Error creating floor texture: %s\n", SDL_GetError());
		SDL_FreeSurface(floorSurface);
		return (NULL);
	}
	SDL_FreeSurface(floorSurface);
	return (floorTexture);
}
