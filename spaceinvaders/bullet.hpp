//
//  bullet.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef bullet_hpp
#define bullet_hpp

#include <stdio.h>
#include "utils.hpp"
#include "gameObject.hpp"
#include "timer.hpp"


class Bullet
{
public:
    Bullet() = default;
    
    Bullet(const Coords& coords);
    
    void update();
    
    void draw();
    
    const Coords& getCoords() const;
    
    // First const is return type, second const is that I'm not changing member variables through the function
    const Coords& getCenter() const;
    
    const int& getRadius();
    
private:
    Coords _coords;
    int _imgWidth = 32;
    int _imgHeight = 32;
    float _bulletSpeed = 500;
    Coords _center;
    int radius;
};

#endif /* bullet_hpp */
