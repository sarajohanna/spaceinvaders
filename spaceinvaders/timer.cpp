//
//  timer.cpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include "timer.hpp"

Timer::Timer()
{
    deltaTime = 0.0;
    thisTime = 0.0;
    lastTime = 0.0;
}

void Timer::setDeltaTime()
{
    thisTime = SDL_GetTicks();
    deltaTime = (thisTime - lastTime)/1000;
    lastTime = thisTime;

}

float Timer::getDeltaTime()
{
    return deltaTime;
}

Timer timer = {};

