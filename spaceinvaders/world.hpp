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
    
    const int& getLives();
    
    void gameOver();
    
private:
    Ship _ship;
    std::vector<Alien> _aliens;
    Coords _coordAlien;
    int _imgWidthAlien = 32;
    int _numAliens = 26;
    int _aliensDistanceFromWall = 70;
    Coords _alienMove;
    int _alienJumpY = 5;
    int _alienJumpX = 5;
    std::vector<Bomb> _bombs;
    //Bomb _bomb;
    double _dtBomb = 0;
    double _dtBombInterval = 3;
    int _shipScores;
    int _shipLives;
    

};

#endif /* world_hpp */
