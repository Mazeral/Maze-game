#include "main.h"

void rayCasting(SDL_Renderer* renderer, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize) {
    float rayAngle = 0.0f;
    float rayDistance = 0.0f;

    for (int i = 0; i < 360; i++) {
        rayAngle = (float)i * 3.14159f / 180.0f;
        rayDistance = 0.0f;

        while (rayDistance < 100.0f) {
            float rayX = player.x + cos(rayAngle) * rayDistance;
            float rayY = player.y + sin(rayAngle) * rayDistance;

            int wallX = (int)rayX / mazeCellSize;
            int wallY = (int)rayY / mazeCellSize;

            if (wallX >= 0 && wallX < mazeWidth && wallY >= 0 && wallY < mazeHeight) {
                if (isWall(wallX, wallY)) {
                    break;
                }
            }

            rayDistance += 1.0f;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, player.x, player.y, player.x + cos(rayAngle) * rayDistance, player.y + sin(rayAngle) * rayDistance);
    }
}
