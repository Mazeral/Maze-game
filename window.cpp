#include"main.h"

/**
 * window - a function to open a SDL window
 * Return: Nothing
 */
void window()
{
	/**
	 * The surface contained by the window
	 * The window we'll be rendering to
	 */
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Event e;
	bool quit = false;

	/* initialize SDL */
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		/* Create window */
		window = SDL_CreateWindow("SDL Tutorial",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			/* Get window surface */
			screenSurface = SDL_GetWindowSurface( window );
			/* Fill the surface white */
			SDL_FillRect(screenSurface, NULL,
					SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			/* Update the surface */
			SDL_UpdateWindowSurface(window);
			/* Hack to get window to stay up */
			while( quit == false )
			{
				while( SDL_PollEvent( &e ) )
				{
					if( e.type == SDL_QUIT ) quit = true;
				}
			}
		}
	}
	/* Destroy window */
	SDL_DestroyWindow( window );
	/* Quit the window */
	SDL_Quit();
}
