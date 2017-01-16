//
//  alien.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef alien_hpp
#define alien_hpp

#include <stdio.h>
#include "utils.hpp"
#include "timer.hpp"

class Alien
{
public:
    Alien() = default;
    
    Alien(const Coords& coords);
    
    //Not used now, maybe later if the aliens should move each X seconds
    void update();
    
    void draw();
        
    const Coords& getCenter() const;
    
    const int& getRadius() const;
    
    const Coords& getCoords() const;
    
    void setCoords(const Coords& moveDistance);

    
private:
    Coords _coords;
    int _imgWidth = 32;
    int _imgHeight = 32;
    Coords _center;
    int radius;
    int _alienSpeed = 1;
    
    // std::vector<Bomb> _bombs;
};


#endif /* alien_hpp */
