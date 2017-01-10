//
//  ship.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef ship_hpp
#define ship_hpp

#include "utils.hpp"
#include "gameObject.hpp"
#include "bullet.hpp"
#include <stdio.h>
#include <vector>

// This ship will have a vector with bullets. It will be called in world and the coordinats will be sent to the constructor when created in world.

class Ship {
public:
    Ship() = default;
    
    Ship(const Coords& coords);
    
    // Move ship with keyboard
    void update();
    
    void draw();

private:
    Coords _coords;
    int _imgWidth = 32;
    int _imgHeight = 32;
    std::vector<Bullet> _bullets;
};


#endif /* ship_hpp */
