#include "main.h"

void rayCasting(SDL_Renderer* renderer, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize)
{
	float rayAngle = -30.0f * 3.14159f / 180.0f; // Start at -30 degrees
	float rayDistance = 0.0f;
	float rayX, rayY;
	int wallX, wallY;

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

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, player.x, player.y, player.x + cos(rayAngle) * rayDistance, player.y + sin(rayAngle) * rayDistance);

	rayAngle += 1.0f * 3.14159f / 180.0f; // Increment angle by 1 degree
	}
}
