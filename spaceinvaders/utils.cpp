//
//  utils.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "utils.hpp"
#include "gameObject.hpp"

#include <cassert>
#include "string"

// This is a const char pointer since thats what SDL wants to have, and in loadSprites a pointer is returned to textures in gameObj.
const char* sprites[NUM_SPRITES] =
{
    "/Users/saralindstrom/Desktop/XcodeProjects/spaceinvaders/spaceinvaders/assets/player.bmp",
    "/Users/saralindstrom/Desktop/XcodeProjects/spaceinvaders/spaceinvaders/assets/enemy1.bmp",
    "/Users/saralindstrom/Desktop/XcodeProjects/spaceinvaders/spaceinvaders/assets/bomb.bmp",
    "/Users/saralindstrom/Desktop/XcodeProjects/spaceinvaders/spaceinvaders/assets/rocket.bmp"
};

// This function loads and adds each sprite from "sprites" above to the array "textures" in gameObj.
void loadSprites()
{
    for (int i = 0; i < static_cast<int>(NUM_SPRITES); ++i)
    {
        gameObj.textures[i] = IMG_LoadTexture(gameObj.renderer, sprites[i]);
        assert(gameObj.textures[i] != nullptr);
    }
}

// This function takes the specific sprite, its coords (where on the screen it should be printed) and the size of it and renders it to the screen. Is used in each class to draw the object (the constructor it each class, e.g ship, creates it)
void drawObject(SPRITES sprite, Coords coords, int width, int height)
{
    SDL_Rect texr;
    texr.w = width;
    texr.h = height;
    texr.x = coords.x;
    texr.y = coords.y;
    SDL_RenderCopy(gameObj.renderer, gameObj.textures[sprite], NULL, &texr);
}

bool keysHeld[NUM_KEYS] = {false};

void drawScoreAndLives(const int& score, const int& lives)
{
    std::string scoreText = "Score: " + std::to_string(score);
    std::string livesText = "Lives: " + std::to_string(lives);
    const char* clivesText = livesText.c_str();
    
    const char* cscoreText = scoreText.c_str();
    
    Coords scorePos;
    scorePos.x = 50;
    scorePos.y = 20;
    int pointsW = 0;
    int pointsH = 0;
    
    gameObj.surface = TTF_RenderText_Solid(gameObj.font, cscoreText, gameObj.color);
    gameObj.texture = SDL_CreateTextureFromSurface(gameObj.renderer, gameObj.surface);
    SDL_QueryTexture(gameObj.texture, NULL, NULL, &pointsW, &pointsH);
    gameObj.dstrect = {static_cast<int>(scorePos.x), static_cast<int>(scorePos.y), pointsW, pointsH };
    
    SDL_RenderCopy(gameObj.renderer, gameObj.texture, NULL, &gameObj.dstrect);

    int livesW = 0;
    int livesH = 0;
    
    gameObj.surface = TTF_RenderText_Solid(gameObj.font, clivesText, gameObj.color);
    gameObj.texture = SDL_CreateTextureFromSurface(gameObj.renderer, gameObj.surface);
    SDL_QueryTexture(gameObj.texture, NULL, NULL, &livesW, &livesH);
    
    Coords livesPos;
    livesPos.x = 800 - livesW -50;
    livesPos.y = 20;
    
    gameObj.dstrect = {static_cast<int>(livesPos.x), static_cast<int>(livesPos.y), livesW, livesH };
    
    SDL_RenderCopy(gameObj.renderer, gameObj.texture, NULL, &gameObj.dstrect);
}

void drawGameOver()
{
    const char* gameOverText = "GAME OVER";
    
    int gameOverW = 0;
    int gameOverH = 0;
    
    gameObj.surface = TTF_RenderText_Solid(gameObj.font, gameOverText, gameObj.color);
    gameObj.texture = SDL_CreateTextureFromSurface(gameObj.renderer, gameObj.surface);
    SDL_QueryTexture(gameObj.texture, NULL, NULL, &gameOverW, &gameOverH);
    
    Coords gameOverPos;
    gameOverPos.x = 100;
    gameOverPos.y = 100;
    
    gameObj.dstrect = {static_cast<int>(gameOverPos.x), static_cast<int>(gameOverPos.y), gameOverW, gameOverH };
    SDL_RenderCopy(gameObj.renderer, gameObj.texture, NULL, &gameObj.dstrect);
}
