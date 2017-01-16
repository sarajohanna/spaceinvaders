//
//  ship.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef ship_hpp
#define ship_hpp

#include "gameObject.hpp"
#include "bullet.hpp"
#include <stdio.h>
#include <vector>

// This ship will have a vector with bullets. It will be called in world and the coordinats will be sent to the constructor when created in world.

class Ship
{
public:
    Ship() = default;
    
    Ship(const Coords& coords);
    
    void update();
    
    void draw();
    
    std::vector<Bullet>& accessBullets();

private:
    Coords _coords;
    int _imgWidth = 32;
    int _imgHeight = 32;
    float _speedX = 200;
    std::vector<Bullet> _bullets;
    Timer _bulletTimer;
    float _dtBullet = 0.1;
};


#endif /* ship_hpp */
