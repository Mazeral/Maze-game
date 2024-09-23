#include "main.h"

SDL_Texture *load_wall_texture(SDL_Renderer *renderer, const char *file_path)
{
    SDL_Surface *surface = IMG_Load(file_path);
    if (!surface)
    {
        printf("Error loading texture: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
    {
        printf("Error creating texture: %s\n", SDL_GetError());
    }

    return texture;
}
