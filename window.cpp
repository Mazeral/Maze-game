#include"main.h"

/**
 * window - a function to open a SDL window
 * Return: Nothing
 */

int window()
{
	int mazeWidth = 10;
	int mazeHeight = 10;
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

	// Define the player's position and size
	SDL_Rect player = { 100, 100, 10, 10 }; // x, y, width, height

	// Define the player's speed
	const int playerSpeed = 5;

	// Define the maze cell size
	const int mazeCellSize = 32;

	// Main loop
	bool running = true;
	SDL_Event event;
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
