#include "main.h"

void draw_ray(SDL_Renderer *renderer, SDL_Rect player, float hitX, float hitY, float rayDistance)
{
    float rayDirX = hitX - player.x;
    float rayDirY = hitY - player.y;
    float rayLength = sqrt(rayDirX * rayDirX + rayDirY * rayDirY);

    float rayEndX = player.x + rayDirX * rayDistance / rayLength;
    float rayEndY = player.y + rayDirY * rayDistance / rayLength;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, player.x, player.y, rayEndX, rayEndY);
}
