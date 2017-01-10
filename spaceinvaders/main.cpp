//
//  main.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-08.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include <iostream>
#include "world.hpp"
#include "gameObject.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0)
        return 1;

    // Create window and renderer with SDL, used for window and render assets in window. These game-stuff like renderer, window etc goes in "gameObject"
    gameObj.winWidth = 800;
    gameObj.winHeight = 600;
    
    // SDL_Create returns an object, created witht the given parameters. win is pointing to that object so the object can be used later on.
    gameObj.win = SDL_CreateWindow("Spade Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gameObj.winWidth, gameObj.winHeight, SDL_WINDOW_SHOWN);
    gameObj.renderer = SDL_CreateRenderer(gameObj.win, -1, SDL_RENDERER_ACCELERATED);
    
    
    // Load assets/sprites
    loadSprites();
    
    // Create a world with ship, aliens, bullets. The world owns aliens and ship. Ship own bullets and the alien owns bomb.
    World world;

    // Create the main game loop (while (true) with breaks)
    while(true) {
        
        // Quit or update world
        if ( SDL_PollEvent(&gameObj.event) ) {
            if (gameObj.event.type == SDL_QUIT)
                break;
            else if (gameObj.event.type == SDL_KEYUP && gameObj.event.key.keysym.sym == SDLK_ESCAPE)
                break;
            else
                world.update();
        }
        
        // Draw updated world with assets (clearing the screen first which is done in draw)
        world.draw();
        
        // Render the screen
        SDL_RenderPresent(gameObj.renderer);
    }
    // Destroy renderer
    SDL_DestroyRenderer(gameObj.renderer);
    // Destroy window
    SDL_DestroyWindow(gameObj.win);
    // Destroy all sprites/textures loaded at the start
    
    return 0;
}
