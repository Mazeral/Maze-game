#include "main.h"

/** isWall - a function to decide if there's a wall or not
 * @x: x axis of the player
 * @y: y axis of the player
 * Return: True (wall) or false (no wall)
 */
bool isWall(int x, int y) 
{
	if (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT)
		return (maze[y][x] == 1);
	else
		return (true); // Assume walls are outside the maze

}
