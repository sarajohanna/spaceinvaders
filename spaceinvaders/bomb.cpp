//
//  bomb.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-23.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "bomb.hpp"

Bomb::Bomb(const Coords& coords)
{
    _coords.x = coords.x;
    _coords.y = coords.y + 30;
}

void Bomb::update()
{
    const float& deltaTime = timer.getDeltaTime();
    _coords.y = (_coords.y + (deltaTime * _bombSpeed));
    _center.x = _coords.x + (_imgWidth/2);
    _center.y = _coords.y + (_imgHeight/2);
    _radius = _imgHeight/2;
}

void Bomb::draw()
{
    drawObject(SPRITE_BOMB, _coords, _imgWidth, _imgHeight);
}

const Coords& Bomb::getCoords()
{
    return _coords;
}

const Coords& Bomb::getCenter()
{
    return _center;
}

const int& Bomb::getRadius()
{
    return _radius;
}
