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

	/* Initialized SDL*/
	sdl_init();
	/* Created our window, defined the size and the pos on the screen*/
	window = create_window();
	/* renderer is an essential component that plays a crucial
	 * role in rendering graphics, text, and other visual elements on the screen.*/
	renderer = create_renderer(window);


	// Main loop
	while (running) {
	    while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
		    running = false;
		}
	    }

	    // Get the current key state
	    const Uint8* keystates = SDL_GetKeyboardState(NULL);

	    // Move the player based on the key state
	    if (keystates[SDL_SCANCODE_UP]) {
		player.y -= playerSpeed;
	    }
	    if (keystates[SDL_SCANCODE_DOWN]) {
		player.y += playerSpeed;
	    }
	    if (keystates[SDL_SCANCODE_LEFT]) {
		player.x -= playerSpeed;
	    }
	    if (keystates[SDL_SCANCODE_RIGHT]) {
		player.x += playerSpeed;
	    }

	    // Ensure the player stays within the window boundaries
	    if (player.x < 0) {
		player.x = 0;
	    }
	    if (player.y < 0) {
		player.y = 0;
	    }
	    if (player.x + player.w > 640) {
		player.x = 640 - player.w;
	    }
	    if (player.y + player.h > 480) {
		player.y = 480 - player.h;
	    }

	    // Check for collisions with the maze
	    int mazeX = player.x / mazeCellSize;
	    int mazeY = player.y / mazeCellSize;
	    if (mazeY < mazeHeight && mazeX < mazeWidth && maze[mazeY][mazeX] == 1) {
		// If the player collides with a wall, move them back
		if (keystates[SDL_SCANCODE_UP]) {
		    player.y += playerSpeed;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
		    player.y -= playerSpeed;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
		    player.x += playerSpeed;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
		    player.x -= playerSpeed;
		}
	    }

	    // Clear the screen
	    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
	    SDL_RenderClear(renderer);

	    // Draw the maze
	    for (int y = 0; y < mazeHeight; y++) {
		for (int x = 0; x < mazeWidth; x++) {
		    if (maze[y][x] == 1) {
			SDL_Rect wall = { x * mazeCellSize, y * mazeCellSize, mazeCellSize, mazeCellSize };
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
			SDL_RenderFillRect(renderer, &wall);
		    }
		}
	    }

	    // Draw the player
	    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
	    SDL_RenderFillRect(renderer, &player);

	    // Update the screen
	    SDL_RenderPresent(renderer);

	    // Cap the frame rate
	    SDL_Delay(1000 / 60);
	}

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
