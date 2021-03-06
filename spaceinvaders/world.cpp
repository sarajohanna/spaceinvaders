//
//  world.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "world.hpp"
#include <cmath>
#include <vector>

World::World()
{
    // Create ship
    Coords coordShip;
    coordShip.x = gameObj.winWidth/2;
    coordShip.y = gameObj.winHeight/1.1;
    _ship = Ship(coordShip);
    _shipScores = 0;
    _shipLives = 3;
    
    // Create vector with aliens
    Coords coordAlien;
    coordAlien.x = ((gameObj.winWidth)/(_numAliens/2)) + _aliensDistanceFromWall;
    
    _aliens.reserve(_numAliens);
    int start = coordAlien.x;
    
    // Line 1 with aliens
    for (int i = 0; i < _numAliens/2; ++i)
    {
        coordAlien.y = gameObj.winHeight/2 - 50;
        _aliens.push_back(Alien(coordAlien));
        coordAlien.x = coordAlien.x + (gameObj.winWidth - (start * 2 + _imgWidthAlien))/((_numAliens/2) - 1);
    }
    
    // Line 2 with aliens
    coordAlien.x = start;
    for (int i = _numAliens/2; i < _numAliens; ++i)
    {
        coordAlien.y = gameObj.winHeight/2;
        _aliens.push_back(Alien(coordAlien));
        coordAlien.x = coordAlien.x + (gameObj.winWidth - (start * 2 + _imgWidthAlien))/((_numAliens/2) - 1);
    }
}

void World::update()
{
    _ship.update();
    
    // Set alien movement
    _alienMove.y = _alienJumpY;
    
    int alienMaxX = 0;
    int alienMinX = gameObj.winWidth;
    
    for (int i = 0; i < _aliens.size(); i++)
    {
        // Get aliens max and min x-position (max for the one farthest to the right and min for the one farthest to the left)
        if (_aliens[i].getCoords().x > alienMaxX)
            alienMaxX = _aliens[i].getCoords().x;
        
        else if (_aliens[i].getCoords().x < alienMinX)
            alienMinX = _aliens[i].getCoords().x;
    }
    
    if (alienMaxX >= 750)
        _alienMove.x = -_alienJumpX;
    
    else if (alienMinX <= 30)
        _alienMove.x = _alienJumpX;
    
    // If alien close to edges of screen, move down and reverse direction
    if ((alienMaxX >= 750)||(alienMinX <= 30))
    {
        for (int j = 0; j < _aliens.size(); ++j)
        {
            _aliens[j].setCoords(_alienMove);
        }
    }
    
    // If not, move horisontally
    else
    {
        for (int j = 0; j < _aliens.size(); ++j)
        {
            _aliens[j].update(j, (int)_aliens.size());
        }
    }
    
    //Bombs that will be dropped from the x/y coords of an alien in the lowest row
    const float& deltaTime = timer.getDeltaTime();
    
    _dtBomb = fmax(-_dtBombInterval, _dtBomb - deltaTime);
    
    //Looping through aliens
    for (int i = 0; i < _aliens.size(); ++i)
    {
        //If the inteval has passed make bomb drop with a certain likelihood for each alien
        if (_dtBomb - _dtBombInterval < 0)
        {
            double r = rand();
            double rd = r/RAND_MAX;

            if (rd > 0.9)
            {
                _bombs.push_back(Bomb(_aliens[i].getCoords()));
                _dtBomb += _dtBombInterval;
            }
        }
    
    }
    
    for (int i = 0; i < _bombs.size(); ++i)
    {
        _bombs[i].update();
    }
    

    //Collision detection alien and bullet
    for (int i = 0; i < _aliens.size(); ++i)
    {

        const int& alienRadius = _aliens[i].getRadius();
        const Coords& alienCenter = _aliens[i].getCenter();
        
        //Get all bullets from ship
        std::vector<Bullet>& bullets = _ship.accessBullets();
        
        for (int j = 0; j < bullets.size(); ++j)
        {
            //int bulletRadius = bullets[j].getRadius();
            const Coords& bulletCenter = bullets[j].getCenter();
            double distance = sqrt(pow((bulletCenter.y - alienCenter.y), 2) + pow((bulletCenter.x - alienCenter.x), 2));
            
            if (distance < alienRadius)
            {
                //Delete alien
                _aliens[i] = _aliens[_aliens.size()-1];
                _aliens.pop_back();
                
                //Delete bullet
                bullets[j] = bullets[bullets.size()-1];
                bullets.pop_back();
                
                _shipScores += 10;
                
                --i;
                break;
            }
        }
    }
    
    //Collision detection ship and bomb
    for (int i = 0; i < _bombs.size(); ++i)
    {
        const int& bombRadius = _bombs[i].getRadius();
        const Coords& bombCenter = _bombs[i].getCenter();
        const Coords& shipCenter = _ship.getCenter();
        
        double distance = sqrt(pow((shipCenter.y - bombCenter.y), 2) + pow((shipCenter.x - bombCenter.x), 2));
        
        if (distance < bombRadius*2)
        {
            //Delete bomb
            _bombs[i] = _bombs[_bombs.size()-1];
            _bombs.pop_back();
            
            -- _shipLives;
            --i;
            break;
        }
    }
}

void World::draw()
{
    SDL_RenderClear(gameObj.renderer);
    
    if(_shipLives <= 0)
    {
        drawGameOver();
    }

    
    drawScoreAndLives(_shipScores, _shipLives);
        
    _ship.draw();
    for (int i = 0; i < _bombs.size(); ++i)
    {
        _bombs[i].draw();
    }
    for (int i = 0; i < _aliens.size(); ++i)
    {
        _aliens[i].draw();
    }
}

const int& World::getLives()
{
    return _shipLives;
}

void World::gameOver()
{
    drawGameOver();
    
}

