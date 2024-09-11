#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL3/SDL.h>
#include <stdio.h>
/*The maze:
 * A 2d array with 1 and zero
 * 1 represents the walls
 * 0 represents the spaces in the maze
 */
const int WALL = 1;
const int PATH = 0;

const int maze[10][10] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
    {WALL, PATH, WALL, WALL, PATH, WALL, WALL, WALL, PATH, WALL},
    {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
    {WALL, PATH, WALL, WALL, PATH, WALL, WALL, PATH, WALL, WALL},
    {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
    {WALL, PATH, WALL, WALL, PATH, WALL, WALL, PATH, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};
int window();
void gameloop();
#endif
