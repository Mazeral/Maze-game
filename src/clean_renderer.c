#include "main.h"
/**
 * clear_renderer - Clears the SDL renderer with a black color
 * @renderer: The SDL renderer to be cleared
 *
 * This function sets the renderer's draw color to black and clears the screen.
 */
void clear_renderer(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  /* Set black color */
	SDL_RenderClear(renderer);
}
