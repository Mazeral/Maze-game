#include "main.h"

/**
 * handleMovement - Moves the player based on keyboard input and ray angle.
 * @player: Pointer to the SDL_Rect structure representing the player.
 * @playerSpeed: Integer representing the player's speed.
 * @keystates: Pointer to the state of the keyboard keys.
 * @ray_angle: The angle in which the player is facing and moving.
 */
void handleMovement(SDL_Rect player, int playerSpeed,
		    const Uint8 *keystates, float ray_angle)
{
	int mazeX = player.x / MAZE_CELL_SIZE;
	int mazeY = player.y / MAZE_CELL_SIZE;
	int newX = player.x;
	int newY = player.y;

	if (keystates[SDL_SCANCODE_UP])
	{
		/* Move forward towards the ray casted */
		printf("Moving forward... x,y: %d,%d\n", player.x, player.y);
		newX += cos(ray_angle) * playerSpeed;
		newY += sin(ray_angle) * playerSpeed;
	}

	if (keystates[SDL_SCANCODE_DOWN])
	{
		/* Move backward towards the ray casted */
		newX -= cos(ray_angle) * playerSpeed;
		newY -= sin(ray_angle) * playerSpeed;
	}

	int newMazeX = newX / MAZE_CELL_SIZE;
	int newMazeY = newY / MAZE_CELL_SIZE;
	const int maze[MAZE_WIDTH][MAZE_HEIGHT] = MAZE;

	if (!(newMazeY < 0 || newMazeX < 0 ||
	      newMazeY >= MAZE_HEIGHT || newMazeX >= MAZE_WIDTH ||
	      maze[newMazeY][newMazeX] == 1))
	{
		printf("New x and y: %d,%d\n", player.x, player.y);
		player.x = newX;
		player.y = newY;
	}
}

/**
 * isCollision - Checks if a collision occurs at the given maze coordinates.
 * @mazeX: X-coordinate of the maze.
 * @mazeY: Y-coordinate of the maze.
 * Return: true if collision (maze value is 1), false otherwise.
 */
bool isCollision(int mazeX, int mazeY)
{
	const int maze[MAZE_WIDTH][MAZE_HEIGHT] = MAZE;

	return (mazeY < MAZE_HEIGHT && mazeX < MAZE_WIDTH && maze[mazeY][mazeX] == 1);
}

/**
 * move - Handles player movement based on keyboard input and ray angle.
 * @player: Pointer to the SDL_Rect representing the player's position.
 * @playerSpeed: Integer representing the player's speed.
 * @ray_angle: Float representing the angle in which the player is facing.
 */
void move(SDL_Rect *player, int playerSpeed, float ray_angle)
{
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	handleMovement(*player, playerSpeed, keystates, ray_angle);
}
