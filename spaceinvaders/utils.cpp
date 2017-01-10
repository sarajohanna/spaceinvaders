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



