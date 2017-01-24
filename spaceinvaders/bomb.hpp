//
//  bomb.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-23.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef bomb_hpp
#define bomb_hpp

#include <stdio.h>
#include "utils.hpp"
#include "timer.hpp"

class Bomb
{
public:
    Bomb() = default;
    
    Bomb(const Coords& coords);
    
    void update();
    
    void draw();

    const Coords& getCoords();
    
    const Coords& getCenter();
    
    const int& getRadius();
    
    Coords _coords;
    int _bombSpeed = 100;
    Coords _center;
    int _imgWidth = 32;
    int _imgHeight = 32;
    int _radius;



};

#endif /* bomb_hpp */
