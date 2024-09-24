#include "main.h"
/**
 * init_sdl_ttf - Initializes SDL_ttf and checks for errors
 * Return: 1 on failure, 0 on success
 */
int init_sdl_ttf(void)
{
	if (TTF_Init() == -1)
	{
		printf("TTF_Init error: %s\n", TTF_GetError());
		return (1);
	}
	return (0);
}

/**
 * draw_white_rectangle - Draws a centered white rectangle on the renderer
 * @renderer: The SDL renderer
 */
void draw_white_rectangle(SDL_Renderer *renderer)
{
	int rect_width = 600;
	int rect_height = 200;
	SDL_Rect textRect;

	/* Center the white rectangle */
	textRect.x = (WINDOW_WIDTH - rect_width) / 2;
	textRect.y = (WINDOW_HEIGHT - rect_height) / 2;
	textRect.w = rect_width;
	textRect.h = rect_height;

	/* Draw the white rectangle */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &textRect);
}

/**
 * render_text1 - Renders the welcome text and returns the SDL_Texture
 * @renderer: The SDL renderer
 * @font: The loaded font
 * @text: The message to render
 * @textColor: The color of the text
 * @textSurface: Address of the SDL_Surface pointer for the text
 * Return: The SDL_Texture of the rendered text, or NULL on error
 */
SDL_Texture *render_text1(SDL_Renderer *renderer, TTF_Font *font,
			 const char *text,
			SDL_Color textColor, SDL_Surface **textSurface)
{
	SDL_Texture *textTexture;

	/* Render the text */
	*textSurface = TTF_RenderText_Solid(font, text, textColor);
	if (*textSurface == NULL)
	{
		printf("TTF_RenderText_Solid error: %s\n", TTF_GetError());
		return (NULL);
	}

	/* Create texture from the surface */
	textTexture = SDL_CreateTextureFromSurface(renderer, *textSurface);
	if (textTexture == NULL)
	{
		printf("SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
		SDL_FreeSurface(*textSurface);
		return (NULL);
	}

	return (textTexture);
}

/**
 * welcome_screen - Displays the welcome message on the screen
 * @renderer: The SDL renderer to draw to
 */
void welcome_screen(SDL_Renderer *renderer)
{
	SDL_Surface *textSurface = NULL;
	SDL_Texture *textTexture = NULL;
	TTF_Font *font = NULL;
	SDL_Color textColor = {0, 0, 0};
	SDL_Rect textRect;

	/* Initialize SDL_ttf */
	if (init_sdl_ttf())
		return;
	/* Clear renderer with black */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	/* Draw the white rectangle */
	draw_white_rectangle(renderer);
	/* Load the font */
	font = TTF_OpenFont("../depedencies/Tiny5-Regular.ttf", 40);
	if (font == NULL)
	{
		printf("TTF_OpenFont error: %s\n", TTF_GetError());
		return;
	}
	/* Render the welcome text */
	textTexture = render_text1(renderer, font, "Welcome to the Maze Game!",
			   textColor, &textSurface);
	if (textTexture == NULL)
	{
		TTF_CloseFont(font);
		return;
	}
	textRect.x = (WINDOW_WIDTH - textSurface->w) / 2;
	textRect.y = (WINDOW_HEIGHT - textSurface->h) / 2;
	textRect.w = textSurface->w;
	textRect.h = textSurface->h;
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	SDL_RenderPresent(renderer);
	SDL_Delay(4000);
	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
	TTF_Quit();
}
