//
//  timer.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef timer_hpp
#define timer_hpp
#include "gameObject.hpp"


#include <stdio.h>

//The application time based timer
class Timer
{
public:
    //Initializes variables
    Timer();
    
    void setDeltaTime();
    
    float getDeltaTime();
    
private:
    float deltaTime;
    float thisTime;
    float lastTime;
};


#endif /* timer_hpp */
