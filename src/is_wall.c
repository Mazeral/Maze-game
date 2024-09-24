#include "main.h"

/**
 * isWall - Checks if a position in the maze is a wall
 * @x: The x-coordinate of the position
 * @y: The y-coordinate of the position
 *
 * Return: true if the position is a wall, false otherwise
 */
bool isWall(int x, int y)
{
	if (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT)
	{
		return (maze[y][x] == 1);
	}
	else
	{
		return (true); /* Assume walls are outside the maze */
	}
}
