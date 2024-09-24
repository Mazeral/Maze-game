#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280
#define NUM_RAYS 60
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20
#define MAZE_CELL_SIZE 32
#define MAZE \
{ \
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, \
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1 }, \
	{ 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, \
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1 }, \
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 }, \
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1 }, \
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 }, \
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1 }, \
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, \
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1 }, \
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, \
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1 }, \
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }, \
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }, \
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1 }, \
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1 }, \
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1 }, \
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, \
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 }, \
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 } \
}
int sdl_init(void);
SDL_Window *create_window(void);
SDL_Renderer *create_renderer(SDL_Window *);
void move(SDL_Rect *player, int playerSpeed, float ray_angle);
void draw_maze(SDL_Renderer *renderer, SDL_Rect player);
float ray_casting(SDL_Renderer *renderer, SDL_Rect player,
		int maze_width, int maze_height, int mazeCellSize,
		SDL_Texture *wall_texture);
bool isWall(int x, int y);
void draw_floor(SDL_Renderer *renderer,
		SDL_Texture *floor_texture, SDL_Rect player);
SDL_Texture *load_floor_texture(SDL_Renderer *renderer);
SDL_Texture *load_sky_texture(SDL_Renderer *renderer);
SDL_Texture *loadFloor(SDL_Renderer *renderer);
void draw_sky(SDL_Renderer *renderer, SDL_Texture *sky_texture);
void draw_wall(SDL_Renderer *renderer, SDL_Texture *wall_texture,
		float wall_height, int i);
SDL_Texture *load_wall_texture(SDL_Renderer *renderer, const char *file_path);
void update_ray_angle(const Uint8 *keystates, float *ray_angle);
void calculate_ray_distance(float current_angle, SDL_Rect player,
		int maze_width, int maze_height, int mazeCellSize,
		float *rayDistance, float *hitX, float *hitY, int *hitSide);
float calculate_floor_distance(float current_angle, SDL_Rect player,
		int maze_width, int maze_height, int mazeCellSize);
void draw_ray(SDL_Renderer *renderer, SDL_Rect player,
		float hitX, float hitY, float rayDistance);
bool game_running(SDL_Rect player, const Uint8 *keystates);
void welcome_screen(SDL_Renderer *renderer);
void game_won_screen(SDL_Renderer *renderer);
float wrap_angle(float angle);
void welcome_screen(SDL_Renderer *renderer);
void calculate_ray_distance(float current_angle, SDL_Rect player,
			    int mazeWidth, int mazeHeight,
			    int mazeCellSize, float *rayDistance,
			    float *hitX, float *hitY, int *hitSide);
#endif
