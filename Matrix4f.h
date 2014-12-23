//
//  Matrix4f.h
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//
# pragma once
#ifndef __Olive__Matrix4f__
#define __Olive__Matrix4f__

#include <cmath>
#include <stdio.h>
#include "Vector3f.h"

#endif /* defined(__Olive__Matrix4f__) */

class Matrix4f {
public:
    
    float m[4][4];
    
    //  -> Matrix4f*
    // Default constructor for a Matrix4f object.
    // Example: Matrix4f(); builds a matix with all components = 0.0.
    // Strategy: Domain Knowledge
    Matrix4f();
    
    // unsigned, unsigned -> float
    // Given a horizontal and a vertical index return the value of the
    // indexed component.
    // INVARIANTS: i and j are < 4
    // Example: getEntryMatrix4f(0, 0); returns m[0][0].
    // Strategy: Domain Knowledge
    float getEntryMatrix4f(unsigned i, unsigned j);
    
    // int, int, float -> void
    // EFFECT: Given a horizontal and a vertical index set the value of the
    // indexed component to the given float.
    // INVARIANTS: i and j are < 4
    // Example: setEntryMatrix4f(0, 0, 1.0); sets m[0][0] = 1.0.
    // Strategy: Domain Knowledge
    void setEntryMatrix4f(unsigned i, unsigned j, float newValue);
    
    //  -> void
    // EFFECT: Set the matrix to the identity matrix.
    // Example: setIdentityMatrix4f(); sets:
    //  m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 0.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 0.0    m[2][1] = 0.0   m[2][2] = 1.0   m[2][3] = 0.0
    //  m[3][0] = 0.0    m[3][1] = 0.0   m[3][2] = 0.0   m[3][3] = 1.0
    // Strategy: Domain Knowledge
    void setIdentityMatrix4f();
    
    // float, float, float -> void
    // EFFECT: Modify the w component of the 0, 1 and 3 columns by given x, y
    // and z floats.
    // Example: setTranslationMatrix4f(1.0f, 2.0f, 3.0f); sets:
    //  m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 1.0
    //  m[1][0] = 0.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 2.0
    //  m[2][0] = 0.0    m[2][1] = 0.0   m[2][2] = 1.0   m[2][3] = 3.0
    //  m[3][0] = 0.0    m[3][1] = 0.0   m[3][2] = 0.0   m[3][3] = 1.0
    // Strategy: Domain Knowledge
    void setTranslationMatrix4f(float x, float y, float z);
    
    // float, float, float -> void
    // EFFECT: Modify the x, y and z components of the matrix by the given x, y
    // and z degree rotations.
    // Example: setRotationMatrix4f(180.0f, 180.0f, 180.0f); sets:
    //  m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 0.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 0.0    m[2][1] = 0.0   m[2][2] = 1.0   m[2][3] = 0.0
    //  m[3][0] = 0.0    m[3][1] = 0.0   m[3][2] = 0.0   m[3][3] = 1.0
    // Strategy: Function Composition
    void setRotationMatrix4f(float x, float y, float z);
    
    // float, float, float -> void
    // EFFECT: Modify the x, y and z components of the matrix by the given x, y
    // and z degree rotations.
    // Example: setScaleMatrix4f(2.0f, 3.0f, 4.0f); sets:
    //  m[0][0] = 2.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 0.0    m[1][1] = 3.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 0.0    m[2][1] = 0.0   m[2][2] = 4.0   m[2][3] = 0.0
    //  m[3][0] = 0.0    m[3][1] = 0.0   m[3][2] = 0.0   m[3][3] = 1.0
    // Strategy: Function Composition
    void setScaleMatrix4f(float x, float y, float z);
    
    // float, float, float, float, float -> void
    // EFFECT: Modify the matrix components according to given zNear, zFar,
    // screen width, screen height and field of view specifications.
    // Example: setProjectionMatrix4f(0.1f, 1.0f, 800.0f, 600.0f, 270.0f); sets:
    //  m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 0.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 0.0    m[2][1] = 0.0   m[2][2] = 1.0   m[2][3] = 0.0
    //  m[3][0] = 0.0    m[3][1] = 0.0   m[3][2] = 0.0   m[3][3] = 1.0
    // Strategy: Function Composition
    void setProjectionMatrix4f(float zNear, float zFar, float width,
                               float height, float fov);
    
    // Vector3f*, Vector3f* -> void
    // EFFECT: Modify the matrix components according to the given forward and
    // up vectors.
    // Example: setScaleMatrix4f(forward, up);
    // Strategy: Function Composition
    void setCameraMatrix4f(Vector3f* forward, Vector3f* up);
    
    // Matrix4f* -> void
    // EFFECT: Given a pointer to a matrix multiply it by this matrix.
    // Example: myMatrix =
    // (m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 2.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 3.0    m[2][1] = 2.0   m[2][2] = 1.0   m[2][3] = 0.0
    //  m[3][0] = 4.0    m[3][1] = 3.0   m[3][2] = 2.0   m[3][3] = 1.0)
    //  otherMatrix =
    // (m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 2.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 3.0    m[2][1] = 2.0   m[2][2] = 1.0   m[2][3] = 0.0
    //  m[3][0] = 4.0    m[3][1] = 3.0   m[3][2] = 2.0   m[3][3] = 1.0)
    //  myMatrix.multMatrix4f(otherMatrix&) sets myMatrix to:
    // (m[0][0] = 1.0    m[0][1] = 0.0   m[0][2] = 0.0   m[0][3] = 0.0
    //  m[1][0] = 0.0    m[1][1] = 1.0   m[1][2] = 0.0   m[1][3] = 0.0
    //  m[2][0] = 0.0    m[2][1] = 0.0   m[2][2] = 1.0   m[2][3] = 0.0
    //  m[3][0] = 0.0    m[3][1] = 0.0   m[3][2] = 0.0   m[3][3] = 1.0)
    // Strategy: Domain Knowledge
    void multMatrix4f(Matrix4f* n);
    
private:
    
    const double piD = 3.141592653589793238463;
};