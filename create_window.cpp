#include "main.h"

SDL_Window* create_window()
{
    /**
     * The SDL_CreateWindow function is a crucial part
     * of the SDL library that creates a new window for our application
     *
     * Arg1: Window title
     * Arg2 Arg3: The x and y of the window on the screen
     * Args 4 5: Window size
     * Arg6: the initial state of the window.
     * By using SDL_WINDOW_SHOWN, we're telling SDL to make
     * the window visible and show it on the screen immediately after creation
     */
	SDL_Window* window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s", SDL_GetError());
		SDL_Quit();
		return (NULL);
	}
	return (window);
}
