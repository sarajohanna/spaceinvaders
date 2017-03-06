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
    _center.x = _coords.x + _imgWidth/2;
    _center.y = _coords.y + _imgHeight/2;
    
    //Update position of ship with its speed and delta time
    const float& deltaTime = timer.getDeltaTime();
    
    // dtBullet will decrease until it is the same as -interval (how much time between bullets)
    _dtBullet = fmax(_dtBullet - deltaTime, -_dtBulletInterval);
    
    if ((keysHeld[KEY_RIGHT]) && (_coords.x < 750))
        _coords.x += _speedX * deltaTime;
    else if ((keysHeld[KEY_LEFT]) && (_coords.x > 30))
        _coords.x -= (_speedX * deltaTime);
    else if (keysHeld[KEY_SPACE])
    {
        //When dtBullet is -interval, shoot a bullet
        if (_dtBulletInterval + _dtBullet <= 0)
        {
            _bullets.push_back(Bullet(_coords));
            //Reset timer to 0
            _dtBullet += _dtBulletInterval;
        }
    }
    
    // Uppdate bullets and if they are outside of screen, remove them
    for (int i = 0; i < _bullets.size(); ++i)
    {
        _bullets[i].update();
        if (_bullets[i].getCoords().y <= 0)
        {
            _bullets[i] = _bullets[_bullets.size() - 1];
            _bullets.pop_back();
        }
    }
}

void Ship::draw()
{
    drawObject(SPRITE_SHIP, _coords, _imgWidth, _imgHeight);
    for (int i = 0; i < _bullets.size(); ++i)
    {
        _bullets[i].draw();
    }
}

std::vector<Bullet>& Ship::accessBullets()
{
    return _bullets;
}

const Coords& Ship::getCenter() const
{
    return _center;
}

Ship::~Ship()
{
    
}
