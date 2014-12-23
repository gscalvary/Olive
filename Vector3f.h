//
//  Vector3f.h
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//
# pragma once
#ifndef __Olive__Vector3f__
#define __Olive__Vector3f__

#include <cmath>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Quaternion.h"

#endif /* defined(__Olive__Vector3f__) */

class Vector3f {
public:
    
    //  -> Vector3f*
    // Default constructor for a Vector3f object.
    // Example: Vector3f() builds a vector with x, y and z coordinates equal to
    // 0.0.
    // Strategy: Domain Knowledge
    Vector3f();
    
    // float, float, float -> Vector3f*
    // GIVEN an x coordinate, a y coordinate and a z coordinate create a 3
    // dimensional vector.
    // Example: Vector3f* myVector = Vector3f(1.0, 2.0, 1.0);
    // Strategy: Domain Knowledge
    Vector3f(float x, float y, float z);
    
    //  -> float
    // Return the x coordinate of the vector.
    // Example: myVector->getVector3fX() returns x;
    // Strategy: Domain Knowledge
    float getVector3fX();
    
    //  -> float
    // Return the y coordinate of the vector.
    // Example: myVector->getVector3fY() returns y;
    // Strategy: Domain Knowledge
    float getVector3fY();
    
    //  -> float
    // Return the z coordinate of the vector.
    // Example: myVector->getVector3fZ() returns z;
    // Strategy: Domain Knowledge
    float getVector3fZ();
    
    // float -> void
    // Set the x coordinate of the vector.
    // Example: myVector->setVector3fX(3.0) sets x = 3.0;
    // Strategy: Domain Knowledge
    void setVector3fX(float x);
    
    // float -> void
    // Set the y coordinate of the vector.
    // Example: myVector->setVector3fY(3.0) sets y = 3.0;
    // Strategy: Domain Knowledge
    void setVector3fY(float y);
    
    // float -> void
    // Set the z coordinate of the vector.
    // Example: myVector->setVector3fZ(3.0) sets z = 3.0;
    // Strategy: Domain Knowledge
    void setVector3fZ(float z);
    
    //  -> std::string
    // Return the vector as an array of characters.
    // Example: myVector->reportVector3f() returns string "(3.0, 2.0, 1.0)";
    // Strategy: Domain Knowledge
    std::string reportVector3f();
    
    //  -> float
    // Return the length of the vector.
    // Example: Vector3f myVector(2.0, 1.0, 2.0)
    //          myVector->lengthVector3f() returns 3.0;
    // Strategy: Function Composition
    float lengthVector3f();
    
    // Vector3f -> float
    // Return the dot product of this vector and the input vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->dotProductVector3f((2.0, 1.0, 2.0)) returns 6.0;
    // Strategy: Function Composition
    float dotProductVector3f(Vector3f otherVector);
    
    // Vector3f -> void
    // EFFECT: Compute the cross product of this vector and the input vector and
    // store the result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->crossProductVector3f((2.0, 1.0, 2.0)); sets my vector
    //          to (-1.0, -2.0, 2.0)
    // Strategy: Function Composition
    void crossProductVector3f(Vector3f otherVector);
    
    //  -> void
    // EFFECT: Normalize this vector.
    // Example: Vector3f myVector(2.0, 1.0, 2.0)
    //          myVector->normalizeVector3f() sets (0.66, 0.33, 0.66);
    // Strategy: Function Composition
    void normalizeVector3f();
    
    // float, Vector3f -> void
    // EFFECT: Rotate this vector by the given float angle, given in degrees,
    // around the axis, given as the Vector3f, and store the results in this
    // vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->rotateVector3f((180.0), (0.0f, 1.0f, 0.0f) sets the
    //          vector to (-2.0, 0.0, -1.0);
    // Strategy: Function Composition
    void rotateVector3f(float angle, Vector3f axis);
    
    // Vector3f -> void
    // EFFECT: Adds this vector to the passed in vector and stores the result in
    // this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->addVector3f((1.0, 1.0, 1.0)) sets myVector to:
    //          (3.0, 1.0, 2.0);
    // Strategy: Function Composition
    void addVector3f(Vector3f otherVector);
    
    // float -> void
    // EFFECT: Adds the passed in float to all coordinates of this vector and
    // stores the result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->addVector3f(2.0) sets myVector to:
    //          (4.0, 2.0, 3.0);
    // Strategy: Function Composition
    void addVector3f(float scalar);
    
    // Vector3f -> void
    // EFFECT: Subtracts this vector from the passed in vector and storeses the
    // result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->subVector3f((1.0, 1.0, 1.0)) sets my vector to:
    //          (1.0, -1.0, 0.0);
    // Strategy: Function Composition
    void subVector3f(Vector3f otherVector);
    
    // float -> void
    // EFFECT: Subtracts the passed in float from all coordinates of this vector
    // and allocates the result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->subVector3f(2.0) sets myVector to:
    //          (0.0, -2.0, -1.0);
    // Strategy: Function Composition
    void subVector3f(float scalar);
    
    // Vector3f -> void
    // EFFECT: Multiplies this vector by the passed in vector and stores the
    // result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->multVector3f((2.0, 1.0, 3.0)) sets myVector to:
    //          (4.0, 0.0, 3.0);
    // Strategy: Function Composition
    void multVector3f(Vector3f otherVector);
    
    // float -> void
    // EFFECT: Multiplies the passed in float by all coordinates of this vector
    // and stores the result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->multVector3f(2.0) sets myVector to:
    //          (4.0, 0.0, 2.0);
    // Strategy: Function Composition
    void multVector3f(float scalar);
    
    // Vector3f -> void
    // EFFECT: Divides this vector by the passed in vector and stores the result
    // in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->divVector2f((2.0, 1.0, 1.0)) sets myVector to:
    //          (1.0, 1.0, 1.0);
    // Strategy: Function Composition
    void divVector3f(Vector3f otherVector);
    
    // float -> void
    // EFFECT: Divides the passed in float by all coordinates of this vector and
    // stores the result in this vector.
    // Example: Vector3f myVector(2.0, 0.0, 1.0)
    //          myVector->addVector2f(2.0) sets myVector to:
    //          (1.0, 0.0, 0.5);
    // Strategy: Function Composition
    void divVector3f(float scalar);
    
private:
    
    float x;
    float y;
    float z;
    const double piD = 3.141592653589793238463;
};