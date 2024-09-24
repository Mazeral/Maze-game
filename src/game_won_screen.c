#include "main.h"

/**
 * create_text_rectangle - Creates a rectangle for the text.
 * @width: Width of the rectangle.
 * @height: Height of the rectangle.
 * @window_width: Width of the window.
 * @window_height: Height of the window.
 *
 * Return: SDL_Rect representing the text rectangle.
 */
SDL_Rect create_text_rectangle(int width,
			       int height,
			       int window_width,
			       int window_height)
{
	SDL_Rect textRect = {
		(window_width - width) / 2,  /* x: center horizontally */
		(window_height - height) / 2, /* y: center vertically */
		width,
		height
	};

	return (textRect);
}

/**
 * render_text2 - Renders the given text on the screen.
 * @renderer: The SDL renderer used for rendering the text.
 * @font: The font to be used for the text.
 * @text: The text to be rendered.
 * @text_color: The color of the text.
 * @window_width: Width of the window.
 * @window_height: Height of the window.
 *
 * Return: SDL_Texture containing the rendered text texture.
 */
SDL_Texture *render_text2(SDL_Renderer *renderer, TTF_Font *font,
			const char *text, SDL_Color text_color,
			int window_width, int window_height)
{
	SDL_Surface *text_surface = TTF_RenderText_Solid(font, text,
						  text_color);
	SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer,
							  text_surface);

	SDL_Rect text_rect = {
		(window_width - text_surface->w) / 2,  /* x: center horizontally */
		(window_height - text_surface->h) / 2, /* y: center vertically */
		text_surface->w,
		text_surface->h
	};

	SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
	SDL_FreeSurface(text_surface);

	return (text_texture);
}

/**
 * game_won_screen - Displays the game won screen with a message.
 * @renderer: The SDL renderer used for rendering the screen.
 *
 * This function initializes the TTF subsystem, clears the screen, and displays
 * a winning message inside a centered rectangle. It waits for 4 seconds before
 * cleaning up resources and quitting the TTF subsystem.
 */
void game_won_screen(SDL_Renderer *renderer)
{
	const int rect_width = 600;
	const int rect_height = 200;
	SDL_Color text_color = {0, 0, 0}; /* Define the text color as black */
	TTF_Font *font = TTF_OpenFont("../depedencies/Tiny5-Regular.ttf", 40);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Rect text_rect = create_text_rectangle(rect_width,
					    rect_height,
					    WINDOW_WIDTH,
					    WINDOW_HEIGHT);
	SDL_RenderFillRect(renderer, &text_rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *text_texture = render_text2(renderer,
					 font, "You won!",
					 text_color,
					 WINDOW_WIDTH,
					 WINDOW_HEIGHT);

	SDL_RenderPresent(renderer);
	SDL_Delay(4000);

	SDL_DestroyTexture(text_texture);
	TTF_CloseFont(font);
}
