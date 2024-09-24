#include "main.h"
/**
 * update_floor_scroll - Update the scrolling offset for the floor
 * based on player movement.
 * @keystates: The current keyboard state.
 * @playerSpeed: The speed of the player.
 * @floor_scroll_offset_x: Pointer to the floor's horizontal scroll offset.
 * @floor_scroll_offset_y: Pointer to the floor's vertical scroll offset.
 *
 * Description: This function adjusts the scroll offsets of the floor
 * texture when the player moves, creating the illusion of floor movement.
 */
void update_floor_scroll(const Uint8 *keystates, int playerSpeed,
		float *floor_scroll_offset_x, float *floor_scroll_offset_y)
{
	const int FLOOR_WIDTH = WINDOW_WIDTH;  /* Width of the floor texture */
	const int FLOOR_HEIGHT = WINDOW_HEIGHT / 2;  /* Height of the floor */

	/* Move the floor based on arrow key input */
	if (keystates[SDL_SCANCODE_UP])
		*floor_scroll_offset_y -= playerSpeed * 0.5f;  /* Move floor upwards */

	if (keystates[SDL_SCANCODE_DOWN])
		*floor_scroll_offset_y += playerSpeed * 0.5f;  /* Move floor downwards */

	if (keystates[SDL_SCANCODE_LEFT])
		*floor_scroll_offset_x -= playerSpeed * 0.5f;  /* Move floor left */

	if (keystates[SDL_SCANCODE_RIGHT])
		*floor_scroll_offset_x += playerSpeed * 0.5f;  /* Move floor right */

	/* Wrap offsets to create seamless scrolling */
	*floor_scroll_offset_x = fmodf(*floor_scroll_offset_x, FLOOR_WIDTH);
	if (*floor_scroll_offset_x > 0)
		*floor_scroll_offset_x += FLOOR_WIDTH;

	*floor_scroll_offset_y = fmodf(*floor_scroll_offset_y, FLOOR_HEIGHT);
	if (*floor_scroll_offset_y > 0)
		*floor_scroll_offset_y += FLOOR_HEIGHT;
}
