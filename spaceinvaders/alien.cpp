//
//  alien.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "alien.hpp"


Alien::Alien(const Coords& coords)
{
    _coords.x = coords.x;
    _coords.y = coords.y;
    radius = _imgHeight/2;    
}

void Alien::update(const int& index, const int& nrOfAliens)
{
    const float& deltaTime = timer.getDeltaTime();
    
    _coords.x += (_alienSpeed * deltaTime);
    _center.x = _coords.x + (_imgWidth/2);
    _center.y = _coords.y +(_imgHeight/2);

//    För att få dom att "hoppa": Flytta x positioner när dt från lastTimeMoved är y

}

void Alien::draw()
{
    drawObject(SPRITE_ALIEN, _coords, _imgWidth, _imgHeight);
}

const Coords& Alien::getCenter() const
{
    return _center;
}

const int& Alien::getRadius() const
{
    return radius;
}

const Coords& Alien::getCoords() const
{
    return _coords;
}

void Alien::setCoords(const Coords& moveDistans)
{
    _alienSpeed *= -1;
    _coords.y += moveDistans.y;
    _coords.x += moveDistans.x;

}
