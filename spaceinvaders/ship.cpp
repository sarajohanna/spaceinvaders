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

void Ship::move()
{
    float deltaTime = timer.getDeltaTime();
    
    if (keysHeld[KEY_RIGHT])
        _speedX = (100 * deltaTime);
    else if (keysHeld[KEY_LEFT])
        _speedX = -(100 * deltaTime);
    else if (keysHeld[KEY_SPACE])
        _bullets.push_back(Bullet(_coords));
}

void Ship::update()
{
    _coords.x += _speedX;

    for (int i = 0; i < _bullets.size(); ++i) {
        _bullets[i].update();
        if (_bullets[i].getCoords().y <= 0) {
            _bullets[i] = _bullets[_bullets.size() - 1];
            _bullets.pop_back();
        }
    }
}

void Ship::draw()
{
    drawObject(SPRITE_SHIP, _coords, _imgWidth, _imgHeight);
    for (int i = 0; i < _bullets.size(); ++i) {
        _bullets[i].draw();
    }
}

const std::vector<Bullet>& Ship::getBullets()
{
    return _bullets;
}
