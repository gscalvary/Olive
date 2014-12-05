//
//  Time.h
//  Olive
//
//  Created by Christopher Oliver on 12/5/14.
//
//

#ifndef __Olive__Time__
#define __Olive__Time__

#include <stdio.h>
#include <GLFW/glfw3.h>

#endif /* defined(__Olive__Time__) */

class Time {
public:
    
    //  -> Time*
    // Time class constructor that allocates a Time object and returns a
    // pointer to it.
    // Example: Time* myClock = Time();
    // Strategy: Domain Knowledge
    Time();
    
    //  -> float
    // Return the time since the GLFW library initialized, this serves as the
    // measure of the passage of time for the game engine.
    // Example: myClock->getTime();
    // Strategy: Function Composition
    float getTime();
    
    //  -> float
    // Return the delta time held by the Time class instance.
    // Example: myClock->getDeltaTime();
    // Strategy: Domain Knowledge
    float getDeltaTime();
    
    // float -> void
    // Set the Time class instance delta time.
    // Example: myClock->setDeltaTime(0.0);
    // Strategy: Domain Knowledge
    void setDeltaTime(float newDeltaTime);
    
private:
    
    float deltaTime;
};
