#include "main.h"

/**
 * create_renderer - creates the SDL renderer that renderers everything
 * @window: The pointer that handles what will be shown on the window
 * Return: the render pointer
 */
SDL_Renderer *create_renderer(SDL_Window *window)
{
	SDL_Renderer *renderer = SDL_CreateRenderer(window,
					     -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"Could not create renderer: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (NULL);
	}
	return (renderer);
}
