#include "main.h"

/**
 * clear_renderer - clears the renderer of SDL_Renderer
 * @renderer: The renderer
 * Return: nothing
 */
void clear_renderer(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
