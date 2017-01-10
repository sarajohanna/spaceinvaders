//
//  world.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "world.hpp"

World::World()
{
    // Create ship
    Coords coordShip;
    coordShip.x = gameObj.winWidth/2;
    coordShip.y = gameObj.winHeight/1.1;
    _ship = Ship(coordShip);
    
    // Create vector with aliens
    Coords coordAlien;
    coordAlien.x = (gameObj.winWidth)/_numAliens;
    coordAlien.y = gameObj.winHeight/2;
    _aliens.reserve(_numAliens);
    int start = coordAlien.x;
    
    for (int i = 0; i < _numAliens; ++i) {
        _aliens.push_back(Alien(coordAlien));
        coordAlien.x = coordAlien.x + (gameObj.winWidth - (start * 2 + _imgWidthAlien))/(_numAliens - 1);
    }
}

void World::update()
{
    _ship.update();
    //for each alien, call update
    
}

void World::draw()
{
    SDL_RenderClear(gameObj.renderer);
    _ship.draw();
    
    for (int i = 0; i < _aliens.size(); ++i) {
        _aliens[i].draw();
    }

}
