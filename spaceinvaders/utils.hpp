//
//  utils.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>

struct Coords
{
    float x;
    float y;
};

enum SPRITES
{
    SPRITE_SHIP,
    SPRITE_ALIEN,
    SPRITE_BOMB,
    SPRITE_BULLET,
    NUM_SPRITES
};

void loadSprites();

void drawObject(SPRITES sprite, Coords coords, int width, int height);

enum KEYS
{
    KEY_RIGHT,
    KEY_LEFT,
    KEY_SPACE,
    NUM_KEYS
};

extern bool keysHeld[NUM_KEYS];

void drawScoreAndLives(const int& score, const int& lives);

void drawGameOver();



#endif /* utils_hpp */
