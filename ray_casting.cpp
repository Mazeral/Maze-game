#include "main.h"

float rayAngle = 0.0f; // Static variable to store the current rotation angle

void calculateRayDistance(float currentAngle, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize, float* rayDistance, float* rayX, float* rayY, int* wallX, int* wallY)
{
    *rayDistance = 0.0f;

    while (*rayDistance < 100.0f)
    {
        *rayX = player.x + cos(currentAngle) * *rayDistance;
        *rayY = player.y + sin(currentAngle) * *rayDistance;

        *wallX = (int)*rayX / mazeCellSize;
        *wallY = (int)*rayY / mazeCellSize;

        if (*wallX >= 0 && *wallX < mazeWidth && *wallY >= 0 && *wallY < mazeHeight)
        {
            if (isWall(*wallX, *wallY))
            {
                break;
            }
        }

        *rayDistance += 1.0f;
    }
}

void drawWall(SDL_Renderer* renderer, float wallHeight, int i)
{
    SDL_Rect wallRect = { i * 10, (int)((480 - wallHeight) / 2), 10, (int)wallHeight };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &wallRect);
}

void drawRay(SDL_Renderer* renderer, float rayX, float rayY, SDL_Rect player)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, player.x, player.y, rayX, rayY);
}

void updateRayAngle(const Uint8* keystates)
{
    if (keystates[SDL_SCANCODE_LEFT])
    {
        rayAngle -= 0.08f * 3.14159f / 180.0f;
    }
    else if (keystates[SDL_SCANCODE_RIGHT])
    {
        rayAngle += 0.08f * 3.14159f / 180.0f;
    }
}

float rayCasting(SDL_Renderer* renderer, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize)
{
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    for (int i = 0; i < 60; i++)
    { /* Cast 60 rays, each 1 degree apart, covering 60 degrees */
        float currentAngle = rayAngle - 30.0f * 3.14159f / 180.0f + i * 3.14159f / 180.0f;

        float rayDistance;
        float rayX;
        float rayY;
        int wallX;
        int wallY;

        calculateRayDistance(currentAngle, player, mazeWidth, mazeHeight, mazeCellSize, &rayDistance, &rayX, &rayY, &wallX, &wallY);

        float wallHeight = 400.0f / rayDistance;

        drawWall(renderer, wallHeight, i);
        drawRay(renderer, rayX, rayY, player);

        updateRayAngle(keystates);
    }
    return (rayAngle); 
}
