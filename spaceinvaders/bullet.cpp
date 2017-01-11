//
//  bullet.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "bullet.hpp"

Bullet::Bullet(const Coords& coords) {
    _coords.x = coords.x;
    _coords.y = coords.y - 30;
}

void Bullet::update() {
    float deltaTime = timer.getDeltaTime();
    _coords.y = (_coords.y - (deltaTime * _bulletSpeed));
    _centre.x = _coords.x + (_imgWidth/2);
    _centre.y = _coords.y + (_imgHeight/2);
    radius = _imgHeight/2;
}

void Bullet::draw() {
    drawObject(SPRITE_BULLET, _coords, _imgWidth, _imgHeight);
}

const Coords& Bullet::getCoords() {
    return _coords;
}

const Coords& Bullet::getCentre() {
    return _centre;
}

const int& Bullet::getRadius() {
    return radius;
}
