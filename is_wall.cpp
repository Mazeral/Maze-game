#include "main.h"
bool isWall(int x, int y) 
{
    // Replace this with your actual maze data
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

    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        return maze[y][x] == 1;
    } else {
        return true; // Assume walls are outside the maze
    }
}
