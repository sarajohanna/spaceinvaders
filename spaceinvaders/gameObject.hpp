//
//  gameObject.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-08.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef gameObject_hpp
#define gameObject_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "utils.hpp"


struct GameObject
{
    // These are defined in main.
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_Event event;
    
    // Pointer to an array with same length as number of sprites (from enum in utils).
    SDL_Texture* textures[NUM_SPRITES];
    
    // Width and height are defined in main.
    int winWidth;
    int winHeight;
};

// gameObj is a global variable
extern GameObject gameObj;

#endif /* gameObject_hpp */
