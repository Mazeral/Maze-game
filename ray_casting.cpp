#include "main.h"

void rayCasting(SDL_Renderer* renderer, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize)
{
	float rayAngle = 0.0f; // Start at 0 degrees
	float rayDistance = 0.0f;
	float rayX, rayY;
	int wallX, wallY;
	int mouseX, mouseY;
	int prevMouseX = 0;
	float rotationAngle;
	SDL_Rect wallRect;
	float wallHeight;
    // Get the initial mouse position
    SDL_GetMouseState(&mouseX, &mouseY);

    for (int i = 0; i < 60; i++)
    { /* Cast 60 rays, each 1 degree apart */
        rayDistance = 0.0f;

        while (rayDistance < 100.0f)
        {
            rayX = player.x + cos(rayAngle) * rayDistance;
            rayY = player.y + sin(rayAngle) * rayDistance;

            wallX = (int)rayX / mazeCellSize;
            wallY = (int)rayY / mazeCellSize;

            if (wallX >= 0 && wallX < mazeWidth && wallY >= 0 && wallY < mazeHeight)
            {
                if (isWall(wallX, wallY))
                {
                    break;
                }
            }

            rayDistance += 1.0f;
        }

        // Calculate the height of the wall based on its distance from the player
        wallHeight = 400.0f / rayDistance;

        // Draw the wall
        wallRect = { i * 10, (int)((480 - wallHeight) / 2), 10, (int)wallHeight };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &wallRect);

        // Draw the ray
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, player.x, player.y, rayX, rayY);

        // Get the current mouse position
        SDL_GetMouseState(&mouseX, &mouseY);

        // Calculate the rotation angle based on the mouse movement
        rotationAngle = (mouseX - prevMouseX) * 0.01f;
        rayAngle += rotationAngle;

        // Update the previous mouse position
        prevMouseX = mouseX;

        rayAngle += 1.0f * 3.14159f / 180.0f; // Increment angle by 1 degree
    }
}
