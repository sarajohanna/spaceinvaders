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
    
    const float& getDeltaTime() const;

    const float& getThisTime() const;

    
private:
    float deltaTime;
    float thisTime;
    float lastTime;
};

extern Timer timer;



#endif /* timer_hpp */
