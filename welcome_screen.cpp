#include "main.h"


void welcome_screen(SDL_Renderer* renderer) {
    // Ensure SDL_ttf is initialized
    if (TTF_Init() == -1) {
        printf("TTF_Init error: %s\n", TTF_GetError());
        return;
    }

    // Clear the renderer with black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Define the white rectangle dimensions
    int rect_width = 400;
    int rect_height = 200;

    // Center the white rectangle
    SDL_Rect textRect = { 
        (WINDOW_WIDTH - rect_width) / 2,  // x: center horizontally
        (WINDOW_HEIGHT - rect_height) / 2, // y: center vertically
        rect_width, 
        rect_height 
    };

    // Draw the white rectangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &textRect);

    // Load the font
    TTF_Font* font = TTF_OpenFont("Tiny5-Regular.ttf", 40);
    if (font == NULL) {
        printf("TTF_OpenFont error: %s\n", TTF_GetError());
        return;
    }

    // Define the text color as black
    SDL_Color textColor = { 0, 0, 0 };

    // Render the text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Welcome to the Maze Game!", textColor);
    if (textSurface == NULL) {
        printf("TTF_RenderText_Solid error: %s\n", TTF_GetError());
        TTF_CloseFont(font);
        return;
    }

    // Create a texture from the surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        printf("SDL_CreateTextureFromSurface error: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        return;
    }

    // Set the destination rectangle for the text
    SDL_Rect textRect2 = { 
        (WINDOW_WIDTH - textSurface->w) / 2,  // x: center horizontally
        (WINDOW_HEIGHT - textSurface->h) / 2, // y: center vertically
        textSurface->w, 
        textSurface->h 
    };

    // Copy the texture to the renderer
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect2);

    // Present the renderer to the screen
    SDL_RenderPresent(renderer);

    // Wait for 2 seconds
    SDL_Delay(2000);

    // Clean up resources
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    TTF_Quit();  // Quit TTF when done
}
