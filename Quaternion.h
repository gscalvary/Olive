//
//  Quaternion.h
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//
# pragma once
#ifndef __Olive__Quaternion__
#define __Olive__Quaternion__

#include <cmath>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Vector3f.h"

#endif /* defined(__Olive__Quaternion__) */

class Quaternion {
public:
    
    //  -> Quaternion*
    // Default constructor for a Quaternion object.
    // Example: Quaternion(1.0, 1.0, 1.0, 1.0); builds a Quaternion with all
    // components = 1.0.
    // Strategy: Domain Knowledge
    Quaternion(float x, float y, float z, float w);
    
    //  -> float
    // Return the x component of the Quaternion.
    // Example: getXQuaternion() returns x.
    // Strategy: Domain Knowledge
    float getXQuaternion();
    
    //  -> float
    // Return the y component of the Quaternion.
    // Example: getYQuaternion() returns y.
    // Strategy: Domain Knowledge
    float getYQuaternion();
    
    //  -> float
    // Return the z component of the Quaternion.
    // Example: getZQuaternion() returns z.
    // Strategy: Domain Knowledge
    float getZQuaternion();
    
    //  -> float
    // Return the w component of the Quaternion.
    // Example: getWQuaternion() returns w.
    // Strategy: Domain Knowledge
    float getWQuaternion();
    
    // float -> void
    // Set the x component of the Quaternion.
    // Example: setXQuaternion(0.0) set x = 0.0.
    // Strategy: Domain Knowledge
    void setXQuaternion(float x);
    
    // float -> void
    // Set the y component of the Quaternion.
    // Example: setYQuaternion(0.0) set y = 0.0.
    // Strategy: Domain Knowledge
    void setYQuaternion(float y);
    
    // float -> void
    // Set the z component of the Quaternion.
    // Example: setZQuaternion(0.0) set z = 0.0.
    // Strategy: Domain Knowledge
    void setZQuaternion(float z);
    
    // float -> void
    // Set the w component of the Quaternion.
    // Example: setWQuaternion(0.0) set w = 0.0.
    // Strategy: Domain Knowledge
    void setWQuaternion(float w);
    
    //  -> float
    // Return the length of the Quaternion.
    // Example: Quaternion myQuaternion(2.0, 2.0, 2.0, 2.0)
    //          myQuaternion->lengthQuaternion() returns 4.0;
    // Strategy: Function Composition
    float lengthQuaternion();
    
    //  -> void
    // EFFECT: Normalize this Quaternion.
    // Example: Quaternion myQuaternion(2.0, 1.0, 2.0, 1.0)
    //          myQuaternion->normalizeQuaternion() sets
    //          (0.5, 0.25, 0.5, 0.25);
    // Strategy: Function Composition
    void normalizeQuaternion();
    
    //  -> Quaternion
    // Return a new Quaternion object that is the conjugate of this one.
    // Example: Quaternion myQuaternion(2.0, 1.0, 2.0, 1.0)
    //          myQuaternion->conjugateQuaternion() returns
    //          (-2.0, -1.0, -2.0, 1.0);
    // Strategy: Domain Knowledge
    Quaternion conjugateQuaternion();
    
    // Quaternon -> Quaternion
    // Given a Quaternion multiply it with this Quaternion and return a new
    // Quaternion object as a result.
    // Example: Quaternion myQuaternion(2.0, 1.0, 2.0, 1.0)
    //          myQuaternion->multQuaternion(0.0, 0.0, 0.0, 0.0) returns
    //          (0.0, 0.0, 0.0, 0.0);
    // Strategy: Function Composition
    Quaternion multQuaternion(Quaternion otherQuaternion);
    
    // Vector3f -> Quaternion
    // Given a Vector3f multiply it with this Quaternion and return a new
    // Quaternion object as a result.
    // Example: Quaternion myQuaternion(2.0, 1.0, 2.0, 1.0)
    //          myQuaternion->multQuaternion(0.0, 0.0, 0.0) returns
    //          (0.0, 0.0, 0.0, 0.0);
    // Strategy: Function Composition
    Quaternion multQuaternion(Vector3f vector);
    
private:
    
    float x;
    float y;
    float z;
    float w;
    
};