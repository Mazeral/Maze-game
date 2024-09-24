#include "main.h"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include "main.h"
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>


/**
 * init_sdl - Initializes SDL and creates window and renderer
 * @window: Double pointer to the SDL window
 * @renderer: Double pointer to the SDL renderer
 * Return: 0 for success, or 1 for failure
 */
int init_sdl(SDL_Window **window, SDL_Renderer **renderer)
{
	sdl_init();
	*window = create_window();
	if (!*window)
		return (1);

	*renderer = create_renderer(*window);
	if (!*renderer)
		return (1);
	return (0);
}

/**
 * load_resources - Loads game textures and resources
 * @renderer: The SDL renderer
 * @wall_texture: Pointer to the wall texture
 * @sky: Pointer to the sky texture
 * @floor: Pointer to the floor texture
 * Return: 0 for success, or 1 for failure
 */
int load_resources(SDL_Renderer *renderer,
	SDL_Texture **wall_texture, SDL_Texture **sky, SDL_Texture **floor)
{
	*wall_texture = load_wall_texture(renderer, "../depedencies/wall.bmp");
	if (!*wall_texture)
		return (1);

	*sky = load_sky_texture(renderer);
	*floor = load_floor_texture(renderer);
	return (0);
}

/**
 * game_loop - The main game loop
 * @renderer: The SDL renderer
 * @player: The player's SDL_Rect
 * @floor: The floor texture
 * @sky: The sky texture
 * @wall_texture: The wall texture
 * Return: Nothing
 */
void game_loop(SDL_Renderer *renderer, SDL_Rect *player,
	SDL_Texture *floor, SDL_Texture *sky, SDL_Texture *wall_texture)
{
	bool running = true;
	SDL_Event event;
	float ray_angle;
	int playerSpeed = 3;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
		}

		draw_sky(renderer, sky);
		draw_floor(renderer, floor, *player);
		ray_casting(renderer, *player,
				wall_texture,
				&ray_angle);
		move(player, playerSpeed, ray_angle);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 60);
		if (!game_running(player))
		{
			running = false;
			game_won_screen(renderer);
		}
	}
}

/**
 * main - The main function
 * Return: 0 for success
 */
int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *sky = NULL;
	SDL_Texture *wall_texture = NULL;
	SDL_Texture *floor = NULL;
	SDL_Rect player = { 32, 32, 10, 10 };

	if (init_sdl(&window, &renderer) != 0)
	{
		printf("Failed to initialize SDL.\n");
		return (1);
	}

	if (load_resources(renderer, &wall_texture, &sky, &floor) != 0)
	{
		printf("Failed to load resources.\n");
		return (1);
	}

	welcome_screen(renderer);
	game_loop(renderer, &player, floor, sky, wall_texture);

	SDL_DestroyTexture(sky);
	SDL_DestroyTexture(wall_texture);
	SDL_DestroyTexture(floor);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
