//
//  world.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef world_hpp
#define world_hpp

#include "ship.hpp"
#include "alien.hpp"
#include <vector>
#include <stdio.h>

// This world will have a ship (just one object in a variable) and aliens (a vector with aliens)

class World
{
public:
    World();
        
    void update();
    
    void draw();
    
private:
    Ship _ship;
    std::vector<Alien> _aliens;
    int _imgWidthAlien = 32;
    int _numAliens = 26;
    int _aliensDistanceFromWall = 70;
    Coords _alienMove;
    int _alienJumpY = 5;
    int _alienJumpX = 5;
};

#endif /* world_hpp */
