//
//  main.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-08.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include <iostream>
#include "gameObject.hpp"
#include "world.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    // Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0)
        return 1;
    TTF_Init();
    
    // Create window and renderer with SDL, used for window and render assets in window. These game-stuff like renderer, window etc goes in "gameObject"
    gameObj.winWidth = 800;
    gameObj.winHeight = 600;
    
    gameObj.win = SDL_CreateWindow("Spade Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gameObj.winWidth, gameObj.winHeight, SDL_WINDOW_SHOWN);
    gameObj.renderer = SDL_CreateRenderer(gameObj.win, -1, SDL_RENDERER_ACCELERATED);
    gameObj.font = TTF_OpenFont("/Library/Fonts/Silom.ttf", 25);
    gameObj.color = { 255, 255, 255 };

    // Load assets/sprites
    loadSprites();
    
    // Create a world with ship, aliens, bullets. The world owns aliens and ship. Ship own bullets and the alien owns bomb.
    World world;
    
    bool gameIsRunning = true;

    // Create the main game loop (while (true) with breaks)
    while(gameIsRunning)
    {
        timer.setDeltaTime();
        
        if (world.getLives() <= 0) {
            
            
            
            //SDL_RenderClear(gameObj.renderer);
//            for (int i = 0; i < static_cast<int>(NUM_SPRITES); ++i)
//            {
//                SDL_DestroyTexture(gameObj.textures[i]);
//            }
            
            
            //SDL_DestroyTexture(gameObj.texturePoint);
            //SDL_FreeSurface(gameObj.surface);
            

        }
        
        // Event handling
        while ( SDL_PollEvent(&gameObj.event) )
        {
            
            if ((gameObj.event.type == SDL_QUIT)||(gameObj.event.type == SDL_KEYUP && gameObj.event.key.keysym.sym == SDLK_ESCAPE))
            {
                gameIsRunning = false;
                break;
            }
            else if (gameObj.event.type == SDL_KEYDOWN)
            {
                if (gameObj.event.key.keysym.sym == SDLK_RIGHT)
                    keysHeld[KEY_RIGHT] = true;
                else if (gameObj.event.key.keysym.sym == SDLK_LEFT)
                    keysHeld[KEY_LEFT] = true;
                else if(gameObj.event.key.keysym.sym == SDLK_SPACE)
                    keysHeld[KEY_SPACE] = true;
            }
            else if (gameObj.event.type == SDL_KEYUP)
            {
                if (gameObj.event.key.keysym.sym == SDLK_RIGHT)
                    keysHeld[KEY_RIGHT] = false;
                else if (gameObj.event.key.keysym.sym == SDLK_LEFT)
                    keysHeld[KEY_LEFT] = false;
                else if(gameObj.event.key.keysym.sym == SDLK_SPACE)
                    keysHeld[KEY_SPACE] = false;
            }
        }
    
        world.update();

        // Draw updated world with assets (clearing the screen first which is done in draw() in world)
        world.draw();
        
        // Render the screen
        SDL_RenderPresent(gameObj.renderer);
        
        
    }
    
    // Destroy renderer
    SDL_DestroyRenderer(gameObj.renderer);
    // Destroy window
    SDL_DestroyWindow(gameObj.win);
    // Destroy all sprites/textures loaded at the start
    for (int i = 0; i < static_cast<int>(NUM_SPRITES); ++i)
    {
        SDL_DestroyTexture(gameObj.textures[i]);
    }
    
    
    SDL_DestroyTexture(gameObj.texture);
    SDL_FreeSurface(gameObj.surface);
    
    TTF_CloseFont(gameObj.font);
    
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}
