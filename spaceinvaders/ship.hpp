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
#include <algorithm>

// This ship will have a vector with bullets. It will be called in world and the coordinats will be sent to the constructor when created in world.

class Ship
{
public:
    Ship() = default;
    
    Ship(const Coords& coords);
    
    void update();
    
    void draw();
    
    std::vector<Bullet>& accessBullets();
    
    const Coords& getCenter() const;
    
private:
    Coords _coords;
    Coords _center;
    int _imgWidth = 32;
    int _imgHeight = 32;
    float _speedX = 200;
    std::vector<Bullet> _bullets;
    double _dtBullet = 0.0;
    double _dtBulletInterval = 0.2;
};


#endif /* ship_hpp */
