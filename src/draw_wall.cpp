#include "main.h"
/** 
 * draw_wall - function that draws the wall
 * @renderer: The renderer
 * @wallHeight: The wallHeight to draw
 * @i: represent the number of ray
 * Return: Nothing
 */
#define TEXTURE_HEIGHT 480  // Higher resolution texture for better quality
#define TEXTURE_WIDTH 480   // Higher resolution texture width
#define WALL_SEGMENTS 60
void draw_wall(SDL_Renderer *renderer, SDL_Texture *wall_texture, float wall_height, int i)
{
    SDL_Rect wall_rect;
    SDL_Rect tex_rect;

    // Calculate the x position of the wall segment
    int wall_x = (i * WINDOW_WIDTH) / NUM_RAYS;

    // Wall segment position on screen (i-th vertical strip)
    wall_rect.x = wall_x;  // Use the calculated x position
    wall_rect.y = (WINDOW_HEIGHT - (int)wall_height) / 2;  // Center the wall vertically
    wall_rect.w = WINDOW_WIDTH / NUM_RAYS;  // Use a width that is proportional to the screen width
    wall_rect.h = (int)wall_height;  // Height of the wall

    // Texture rectangle: map the texture based on the wall hit position
    tex_rect.x = (i % TEXTURE_WIDTH) * (TEXTURE_WIDTH / WALL_SEGMENTS);  // Use a portion of the texture width
    tex_rect.y = 0;
    tex_rect.w = (TEXTURE_WIDTH / WALL_SEGMENTS);  // Use a portion of the texture width
    tex_rect.h = TEXTURE_HEIGHT;  // Use the texture height

    // Render the wall
    SDL_RenderCopy(renderer, wall_texture, &tex_rect, &wall_rect);
}
