//
//  ship.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "ship.hpp"

Ship::Ship(const Coords& coords)
{
    _coords.x = coords.x;
    _coords.y = coords.y; 
}

void Ship::update()
{
        float deltaTime = timer.getDeltaTime();
    
        if (gameObj.event.key.keysym.sym == SDLK_RIGHT)
            _coords.x += (0.1 * deltaTime);
        else if (gameObj.event.key.keysym.sym == SDLK_LEFT)
            _coords.x -= (0.1 * deltaTime);
        else if (gameObj.event.key.keysym.sym == SDLK_SPACE)
            
                _bullets.push_back(Bullet(_coords));    
}

void Ship::draw()
{
    drawObject(SPRITE_SHIP, _coords, _imgWidth, _imgHeight);
    
    for (int i = 0; i < _bullets.size(); ++i) {
        _bullets[i].update();
        if (_bullets[i].getCoords().y <= 0) {
            _bullets[i] = _bullets[_bullets.size() - 1];
            _bullets.pop_back();
        }
    }
    for (int i = 0; i < _bullets.size(); ++i) {
        _bullets[i].draw();
    }
}
