//
//  alien.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "alien.hpp"

Alien::Alien(const Coords& coords) {
    _coords.x = coords.x;
    _coords.y = coords.y;
}

void Alien::update() {

}

void Alien::draw() {
    drawObject(SPRITE_ALIEN, _coords, _imgWidth, _imgHeight);
}
