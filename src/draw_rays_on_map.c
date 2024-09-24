#include "main.h"

/**
 * draw_ray - Draws a ray from the player to the hit point
 * @renderer: The SDL renderer used to draw the ray
 * @player: SDL_Rect structure representing the player
 * @hitX: The x-coordinate of the ray hit point
 * @hitY: The y-coordinate of the ray hit point
 * @rayDistance: The distance from the player to the ray hit point
 *
 * This function calculates the ray's direction and length, then draws the ray
 * from the player to the hit point using the renderer.
 *
 * Return: Nothing
 */
void draw_ray(SDL_Renderer *renderer,
	      SDL_Rect player,
	      float hitX,
	      float hitY,
	      float rayDistance)
{
	float rayDirX = hitX - player.x;
	float rayDirY = hitY - player.y;
	float rayLength = sqrt(rayDirX * rayDirX + rayDirY * rayDirY);

	float rayEndX = player.x + rayDirX * rayDistance / rayLength;
	float rayEndY = player.y + rayDirY * rayDistance / rayLength;

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, player.x, player.y, rayEndX, rayEndY);
}
