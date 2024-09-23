#include "main.h"


void game_won_screen(SDL_Renderer* renderer) {
    int rect_width = 600;
    int rect_height = 200;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect textRect = { 
        (WINDOW_WIDTH - rect_width) / 2,  // x: center horizontally
        (WINDOW_HEIGHT - rect_height) / 2, // y: center vertically
        rect_width, 
        rect_height 
    };
    SDL_RenderFillRect(renderer, &textRect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    TTF_Font* font = TTF_OpenFont("Tiny5-Regular.ttf", 40);
    SDL_Color textColor = { 0, 0, 0 }; // Define the text color as black
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "You won!", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect2 = { 200, 200, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect2);
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
}
