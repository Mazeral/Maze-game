#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>
/*The maze:
 * A 2d array with 1 and zero
 * 1 represents the walls
 * 0 represents the spaces in the maze
 */

extern float rayAngle; // Global variable to store the current rotation angle
const int mazeWidth = 10;
const int mazeHeight = 10;
const int mazeCellSize = 32;
const int maze[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int window();
void gameloop();
int sdl_init();
SDL_Window* create_window();
SDL_Renderer* create_renderer(SDL_Window *);
void move(SDL_Rect* player, int playerSpeed, float);
void draw_maze(SDL_Renderer *renderer);
float rayCasting(SDL_Renderer* renderer, SDL_Rect player, int mazeWidth, int mazeHeight, int mazeCellSize);
bool isWall(int x, int y);
#endif
