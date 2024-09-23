#include "main.h"
#include <SDL2/SDL_keyboard.h>
float floor_scroll_offset_x = 0.0f;
float floor_scroll_offset_y = 0.0f;
/**
 * main - the main function
 * Return: 0 for successs
 */

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	/* Define the player's position and size */
	SDL_Rect player = { 32, 32, 10, 10 }; // x, y, width, height
	/* Define the player's speed */
	const int playerSpeed = 5;
	/* Define the maze cell size */
	const int mazeCellSize = 32;
	/* The state of the game */
	bool running = true;
	/* The variables that handle our events */
	SDL_Event event;
	float ray_angle;
	SDL_Texture *sky = NULL;
	SDL_Texture *wall_texture = NULL;
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	SDL_Texture *floor = NULL;

	/* Initialize SDL */
	sdl_init();

	/* Create the window */
	window = create_window();

	/* Create the renderer */
	renderer = create_renderer(window);

	/* Load the wall texture */
	wall_texture = load_wall_texture(renderer, "wall.bmp");
	if (!wall_texture)
	{
		printf("Failed to load wall texture.\n");
		return (1);
	}

	/* Load the floor and sky texture once */
	sky = load_sky_texture(renderer);
	floor = load_floor_texture(renderer);

	/* The game loop */
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
		}

		/* Draw the sky at the top */
		draw_sky(renderer, sky);
		draw_maze(renderer ,player);
		    draw_floor(renderer, floor, player);

		/* Draw the floor at the bottom */

		/* Ray casting and player movement */
		ray_angle = ray_casting(renderer, player,
				mazeWidth, mazeHeight,
				mazeCellSize, wall_texture);
		move(&player, playerSpeed, ray_angle);

		/* Update the screen (present the renderer) */
		SDL_RenderPresent(renderer);

		/* Cap the frame rate */
		SDL_Delay(1000 / 60);
		if (game_running(player, keystates) == false)
			running = game_running(player, keystates);
	}

	/* Cleanup */
	SDL_DestroyTexture(sky);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(floor);
	SDL_Quit();

	return (0);
}
