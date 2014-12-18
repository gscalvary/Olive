//
//  Transform.h
//  Olive
//
//  Created by Christopher Oliver on 12/17/14.
//
//
#pragma once
#ifndef __Olive__Transform__
#define __Olive__Transform__

#include <stdio.h>
#include "Matrix4f.h"
#include "Vector3f.h"

#endif /* defined(__Olive__Transform__) */

class Transform {
public:
    
    //  -> Transform*
    // Default constructor for the Transform class which returns a pointer to
    // the Transform object allocated.
    // Example: Transform(); returns a pointer to the new Transform object.
    // Strategy: Domain Knowledge
    Transform();
    
    //  -> void
    // Default destructor for the Transform class which deallocates the
    // Transform object.
    // Example: ~Transform(); deallocates the Transform object.
    // Strategy: Domain Knowledge
    ~Transform();
    
    //  -> Vector3f*
    // Return a pointer to the translation Vector3f of this Transform object.
    // Example: myTransform.getTranslationPtr(); returns a pointer to
    // translation.
    // Strategy: Domain Knowledge
    Vector3f* getTranslationPtr();
    
    // Vector3f& -> void
    // Given an address of a Vector3f set this objects translation to it.
    // Example: myTransform.setTranslation(vector3f&); sets translation to the
    // given address.
    // Strategy: Domain Knowledge
    void setTranslation(Vector3f& translationAddress);
    
    // float, float, float -> void
    // Given the x, y and z coordinates of a Vector3f set the translation's
    // atrtributes to them.
    // Example: myTransform.setTranslation(0.0f, 1.0f, 2.0f); sets translation
    // x coordiante to 0.0f, y coordinate to 1.0f and z coordinate to 2.0f.
    // Strategy: Function Composition
    void setTranslation(float x, float y, float z);
    
    //  -> Matrix4f*
    // Return a pointer to the transformation matrix.
    // EFFECT: transforms the matrix by the translation vector.
    // Example: myTransform.getTransformationPtr(); returns a pointer to the
    // transformation matrix.
    // Strategy: Domain Knowledge
    Matrix4f* getTransformationPtr();
    
private:
    
    Vector3f* translation;
    Matrix4f* transformation;
};
