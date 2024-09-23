#include "main.h"
#include <SDL2/SDL_rect.h>

float calculate_floor_distance(float current_angle, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize)

{
    float rayDistance = 0.0f;
    float deltaX = cos(current_angle);
    float deltaY = sin(current_angle);

    const float increment = 0.1f;  // Larger increment value for simple raycasting
    const float max_distance = 100.0f;  // Maximum distance

    while (rayDistance < max_distance)
    {
        float hitX = player.x + deltaX * rayDistance;
        float hitY = player.y + deltaY * rayDistance;

        // Check if the ray hits the floor
        if (hitY > mazeHeight * mazeCellSize - player.y)
        {
            break;
        }

        rayDistance += increment;
    }

    return rayDistance;
}
