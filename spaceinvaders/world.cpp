//
//  world.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "world.hpp"
#include <cmath>
#include<vector>

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

void World::moveObjects() {
    _ship.move();
}

void World::update()
{
    _ship.update();
    
    //Collision control.. Ta in det som behövs i funktionen, lägg den i utils?
    
//    for (int i = 0; i < _aliens.size(); ++i) {
//        int alienRadius = _aliens[i].getRadius();
//        Coords alienCentre = _aliens[i].getCentre();
//        int alienY = alienCentre.y;
//        if ()
//    }
    
    
    //Collision detection alien and bullet

    for (int i = 0; i < _aliens.size(); ++i) {
        int alienRadius = _aliens[i].getRadius();
        Coords alienCenter = _aliens[i].getCenter();
        
        //Get bullets here - do i need to do it like this?
        std::vector<Bullet> bullets = _ship.getBullets();
        
        
        
        for (int j = 0; j < bullets.size(); ++j)
        {
            int bulletRadius = bullets[j].getRadius();
            Coords bulletCenter = bullets[j].getCenter();
            double distance = sqrt(pow((bulletCenter.y - alienCenter.y), 2) + pow((bulletCenter.x - alienCenter.x), 2));
            
            if ((distance) < (alienRadius + bulletRadius))
            {
                //_aliens.erase(_aliens.begin()+i);
                _aliens[i]= _aliens[_aliens.size()-1];
                _aliens.pop_back();
                i--;
            }
        }
    }
    
    
    
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
