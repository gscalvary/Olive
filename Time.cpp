//
//  Time.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/5/14.
//
//

#include "Time.h"

Time::Time() {
    
    deltaTime = 0.0;
}

float Time::getTime() {
    
    return glfwGetTime();
}

float Time::getDeltaTime() {
    
    return deltaTime;
}

void Time::setDeltaTime(float newDeltaTime) {
    
    deltaTime = newDeltaTime;
}