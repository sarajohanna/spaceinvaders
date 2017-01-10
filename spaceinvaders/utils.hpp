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
    int x;
    int y;
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

#endif /* utils_hpp */
