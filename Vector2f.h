//
//  Vector2f.h
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//
# pragma once
#ifndef __Olive__Vector2f__
#define __Olive__Vector2f__

#include <sstream>
#include <stdio.h>
#include <string>

#endif /* defined(__Olive__Vector2f__) */

class Vector2f {
public:

    //  -> Vector2f*
    // Default constructor for a Vector2f object.
    // Example: Vector2f() builds a vector with an x and y coordinate equal to
    // 0.0.
    // Strategy: Domain Knowledge
    Vector2f();
    
    // float, float -> Vector2f*
    // GIVEN an x coordinate and a y coordinate create a 2 dimensional vector.
    // Example: Vector2f* myVector = Vector2f(1.0, 2.0);
    // Strategy: Domain Knowledge
    Vector2f(float x, float y);
    
    //  -> float
    // Return the x coordinate of the vector.
    // Example: myVector->getVector2fX() returns x;
    // Strategy: Domain Knowledge
    float getVector2fX();
    
    //  -> float
    // Return the y coordinate of the vector.
    // Example: myVector->getVector2fY() returns y;
    // Strategy: Domain Knowledge
    float getVector2fY();
    
    // float -> void
    // Set the x coordinate of the vector.
    // Example: myVector->setVector2fX(3.0) sets x = 3.0;
    // Strategy: Domain Knowledge
    void setVector2fX(float x);
    
    // float -> void
    // Set the y coordinate of the vector.
    // Example: myVector->setVector2fY(3.0) sets y = 3.0;
    // Strategy: Domain Knowledge
    void setVector2fY(float y);
    
    //  -> std::string
    // Return the vector as an array of characters.
    // Example: myVector->reportVector2f() returns string "(3.0, 2.0)";
    // Strategy: Domain Knowledge
    std::string reportVector2f();
    
private:
    
    float x;
    float y;
};
