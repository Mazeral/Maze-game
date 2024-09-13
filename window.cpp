#include"main.h"

/**
 * window - a function to open a SDL window
 * Return: Nothing
 */

int window()
{
	int mazeWidth = 10;
	int mazeHeight = 10;
	SDL_Window *window = NULL;
	SDL_Renderer* renderer = NULL;
	// Define the player's position and size
	SDL_Rect player = { 100, 100, 10, 10 }; // x, y, width, height
	// Define the player's speed
	const int playerSpeed = 5;
	// Define the maze cell size
	const int mazeCellSize = 32;
	bool running = true;
	/* The variables that handles our events */
	SDL_Event event;
	float ray_angle;

	/* Initialized SDL*/
	sdl_init();
	/* Created our window, defined the size and the pos on the screen*/
	window = create_window();
	/* renderer is an essential component that plays a crucial
	* role in rendering graphics, text, and other visual elements on the screen.*/
	renderer = create_renderer(window);


	// Main loop
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {
			    running = false;
			}
		}
		/* Handles the movement and collusion */

		/* Clear the screen in white color */
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		draw_maze(renderer);
		/* Ray casting!*/
		ray_angle = rayCasting(renderer, player, mazeWidth, mazeHeight, mazeCellSize);
		move(&player, playerSpeed, ray_angle);
		// /* Draw the player in black */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &player);
		/* Update the screen */
		SDL_RenderPresent(renderer);
		/* Cap the frame rate */
		SDL_Delay(1000 / 60);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}
