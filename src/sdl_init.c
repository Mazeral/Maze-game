#include "main.h"

/**
 * sdl_init - Initializes SDL and its video subsystem.
 *
 * Return: 0 on success, 1 on failure.
 */
int sdl_init(void)
{
	/* Initialize SDL and its functions! */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"Could not initialize SDL: %s",
				SDL_GetError());
		return (1);
	}
	return (0);
}
