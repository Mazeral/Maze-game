#include "main.h"
#define TEXTURE_HEIGHT 480  /* Higher resolution texture for better quality */
#define TEXTURE_WIDTH 480   /* Higher resolution texture width */
#define WALL_SEGMENTS 60

/**
 * draw_wall - Renders a vertical wall segment on the screen
 * @renderer: The SDL renderer used to draw the wall segment
 * @wall_texture: The texture of the wall to be rendered
 * @wall_height: The height of the wall segment to be rendered
 * @i: The index of the current vertical strip of the wall
 *
 * This function calculates the position of a vertical wall segment based
 * on the wall height, index, and ray casting logic. It then maps a portion
 * of the wall texture and renders it on the screen.
 *
 * Return: Nothing
 */
void draw_wall(SDL_Renderer *renderer, SDL_Texture *wall_texture,
	       float wall_height, int i)
{
	SDL_Rect wall_rect;
	SDL_Rect tex_rect;
	int wall_x;

	/* Calculate the x position of the wall segment */
	wall_x = (i * WINDOW_WIDTH) / NUM_RAYS;

	/* Wall segment position on screen (i-th vertical strip) */
	wall_rect.x = wall_x;  /* Use the calculated x position */
	wall_rect.y = (WINDOW_HEIGHT - (int)wall_height) / 2; /* Center vertically */
	wall_rect.w = WINDOW_WIDTH / NUM_RAYS;  /* Width proportional to screen */
	wall_rect.h = (int)wall_height;  /* Height of the wall */

	/* Texture rectangle: map the texture based on the wall hit position */
	tex_rect.x = (i % TEXTURE_WIDTH) * (TEXTURE_WIDTH / WALL_SEGMENTS);
	tex_rect.y = 0;
	tex_rect.w = (TEXTURE_WIDTH / WALL_SEGMENTS);  /* Use portion of texture */
	tex_rect.h = TEXTURE_HEIGHT;  /* Use full texture height */

	/* Render the wall */
	SDL_RenderCopy(renderer, wall_texture, &tex_rect, &wall_rect);
}
