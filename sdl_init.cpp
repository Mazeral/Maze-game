#include "main.h"

int sdl_init(){
	/* Initialize SDL and it's functions! */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize SDL: %s", SDL_GetError());
        return (1);
    }
    return (0);
}
