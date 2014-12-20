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

#include <cmath>
#include <sstream>
#include <stdio.h>
#include <string>

#endif /* defined(__Olive__Vector2f__) */

class Vector2f {
public:

    //  -> Vector2f*
    // Default constructor for a Vector2f object.
    // Example: Vector2f() builds a vector with x and y coordinates equal to
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
    
    //  -> float
    // Return the length of the vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->lengthVector2f() returns 2.0;
    // Strategy: Function Composition
    float lengthVector2f();
    
    // Vector2f -> float
    // Return the dot product of this vector and the input vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->dotProductVector2f((2.0, 1.0)) returns 4.0;
    // Strategy: Function Composition
    float dotProductVector2f(Vector2f otherVector);
    
    //  -> void
    // EFFECT: Normalize this vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->normalizeVector2f() sets (1.0, 0.0);
    // Strategy: Function Composition
    void normalizeVector2f();
    
    // float -> Vector2f
    // EFFECT: Rotate this vector by the given float angle and return it.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->rotateVector2f((180.0)) returns (-1.0, 0.0);
    // Strategy: Function Composition
    Vector2f rotateVector2f(float angle);
    
    // Vector2f -> Vector2f
    // Adds this vector to the passed in vector and allocates the result as a
    // new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->addVector2f((1.0, 1.0)) returns new object vector2f
    //          (3.0, 1.0);
    // Strategy: Function Composition
    Vector2f addVector2f(Vector2f otherVector);
    
    // float -> Vector2f
    // Adds the passed in float to all coordinates of this vector and allocates
    // the result as a new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->addVector2f(2.0) returns new object vector2f
    //          (4.0, 2.0);
    // Strategy: Function Composition
    Vector2f addVector2f(float scalar);
    
    // Vector2f -> Vector2f
    // Subtracts this vector from the passed in vector and allocates the result
    // as a new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->subVector2f((1.0,  1.0)) returns new object vector2f
    //          (1.0, -1.0);
    // Strategy: Function Composition
    Vector2f subVector2f(Vector2f otherVector);
    
    // float -> Vector2f
    // Subtracts the passed in float from all coordinates of this vector and
    // allocates the result as a new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->subVector2f(2.0) returns new object vector2f
    //          (0.0, -2.0);
    // Strategy: Function Composition
    Vector2f subVector2f(float scalar);
    
    // Vector2f -> Vector2f
    // Multiplies this vector by the passed in vector and allocates the result
    // as a new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->multVector2f((2.0,  1.0)) returns new object vector2f
    //          (4.0, 0.0);
    // Strategy: Function Composition
    Vector2f multVector2f(Vector2f otherVector);
    
    // float -> Vector2f
    // Multiplies the passed in float by all coordinates of this vector and
    // allocates the result as a new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->multVector2f(2.0) returns new object vector2f
    //          (4.0, 0.0);
    // Strategy: Function Composition
    Vector2f multVector2f(float scalar);
    
    // Vector2f -> Vector2f
    // Divides this vector by the passed in vector and allocates the result as a
    // new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->divVector2f((2.0,  1.0)) returns new object vector2f
    //          (1.0, 1.0);
    // Strategy: Function Composition
    Vector2f divVector2f(Vector2f otherVector);
    
    // float -> Vector2f
    // Divides the passed in float by all coordinates of this vector and
    // allocates the result as a new vector.
    // Example: Vector2f myVector(2.0, 0.0)
    //          myVector->addVector2f(2.0) returns new object vector2f
    //          (1.0, 0.0);
    // Strategy: Function Composition
    Vector2f divVector2f(float scalar);
    
private:
    
    float x;
    float y;
    const double piD = 3.141592653589793238463;
};
