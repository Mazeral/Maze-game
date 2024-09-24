#include "main.h"
/**
 * calculate_ray_distance - a function to calculate the distance to the wall
 * @current_angle: The current angle of the ray
 * @player: The player position
 * @mazeWidth: The width of the maze
 * @mazeHeight: The height of the maze
 * @mazeCellSize: The size of the maze cell
 * @rayDistance: The distance to the wall
 * @hitX: The x position of the hit
 * @hitY: The y position of the hit
 * @hitSide: The side of the hit (0 for x, 1 for y)
 * Return: Nothing
 */
void calculate_ray_distance(float current_angle, SDL_Rect player,
			    int mazeWidth, int mazeHeight,
			    int mazeCellSize, float *rayDistance,
			    float *hitX, float *hitY, int *hitSide)
{
	*rayDistance = 0.0f;
	float deltaX = cos(current_angle);
	float deltaY = sin(current_angle);
	const float increment = 0.1f; /*Larger increment value for simple raycasting*/
	const float max_distance = 100.0f;  /* Arbitrary maximum distance */
	int wallX = 0;
	int wallY = 0;

	while (*rayDistance < max_distance)
	{
		*hitX = player.x + deltaX * *rayDistance;
		*hitY = player.y + deltaY * *rayDistance;
		wallX = (int)(*hitX) / mazeCellSize;
		wallY = (int)(*hitY) / mazeCellSize;

		/*Check if the current position hits a wall*/
		if (isWall(wallX, wallY))
		{
			*hitSide = (fabs(*hitX - wallX * mazeCellSize)
				< fabs(*hitY - wallY * mazeCellSize)) ? 0 : 1;
			break;
		}

		*rayDistance += increment;
	}
}
