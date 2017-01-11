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


class Bullet {
public:
    Bullet() = default;
    
    Bullet(const Coords& coords);
    
    void update();
    
    void draw();
    
    const Coords& getCoords();
    
    void setCollisionData();
    
    const Coords& getCentre();
    
    const int& getRadius();
    
private:
    Coords _coords;
    int _imgWidth = 32;
    int _imgHeight = 32;
    float _bulletSpeed = 300;
    Coords _centre;
    int radius;
};

#endif /* bullet_hpp */
