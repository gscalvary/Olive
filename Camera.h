//
//  Camera.h
//  Olive
//
//  Created by Christopher Oliver on 12/22/14.
//
//
#pragma once
#ifndef __Olive__Camera__
#define __Olive__Camera__

#include <stdio.h>
#include "Vector3f.h"

#endif /* defined(__Olive__Camera__) */

class Camera {
public:
    
    //  -> Camera*
    // Default constructor for a camera object.
    // Example: Camera* myCamera = Camera()
    // Function Composition
    Camera();
    
    // Vector3f, Vector3f, Vector3f -> Camera*
    // Given a Vector3f representing the current position, a Vector3f
    // representing a forward direction and a Vector3f representing an up
    // direction construct a camera object.
    // Example: Camera* myCamera = Camera(Vector3f(0.0f, 0.0f, 0.0f),
    //                                    Vector3f(0.0f, 0.0f, 1.0f),
    //                                    Vector3f(0.0f, 1.0f, 0.0f)
    // Function Composition
    Camera(Vector3f pos, Vector3f forward, Vector3f up);
    
    //  -> Vector3f*
    // Return a pointer to the pos of the Camera.
    // Example: getPosCamera() returns pos;
    // Strategy: Domain Knowledge
    Vector3f* getPosCamera();
    
    // Vector3f* -> void
    // Sets the pointer for the pos of the Camera to the passed in Vector3f.
    // Example: setPosCamera(Vector3f* newPos) sets pos to newPos;
    // Strategy: Domain Knowledge
    void setPosCamera(Vector3f* newPos);
    
    //  -> Vector3f*
    // Return a pointer to the forward of the Camera.
    // Example: getForwardCamera() returns forward;
    // Strategy: Domain Knowledge
    Vector3f* getForwardCamera();
    
    // Vector3f* -> void
    // Sets the pointer for the forward of the Camera to the passed in Vector3f.
    // Example: setForwardCamera(Vector3f* newForward) sets forward to
    // newForward;
    // Strategy: Domain Knowledge
    void setForwardCamera(Vector3f* newForward);
    
    //  -> Vector3f*
    // Return a pointer to the up of the Camera.
    // Example: getUpCamera() returns up;
    // Strategy: Domain Knowledge
    Vector3f* getUpCamera();
    
    //  -> Vector3f*
    // EFFECT: calculates the left vector by taking the cross-product of the
    // up and forward vectors then returns a pointer to the left vector.
    // Example: getLeftCamera() returns left;
    // Strategy: Function Composition
    Vector3f* getLeftCamera();
    
    //  -> Vector3f*
    // EFFECT: calculates the right vector by taking the cross-product of the
    // forward and up vectors then returns a pointer to the right vector.
    // Example: getRightCamera() returns right;
    // Strategy: Function Composition
    Vector3f* getRightCamera();
    
    // Vector3f* -> void
    // Sets the pointer for the up of the Camera to the passed in Vector3f.
    // Example: setUpCamera(Vector3f* newUp) sets up to newUp;
    // Strategy: Domain Knowledge
    void setUpCamera(Vector3f* newUp);
    
    // Vector3f, float -> void
    // EFFECT: Given a Vector3f direction and a float amount move the position
    // of the camera that amount in that direction.
    // Example: myCamera.moveCamera(Vector3f(1.0f, 1.0f, 1.0f), float 2.0f) adds
    // Vector3f(2.0f, 2.0f, 2.0f) to pos.
    // Strategy: Function Composition
    void moveCamera(Vector3f dir, float amt);
    
    // float -> void
    // EFFECT: Given a float angle in degrees rotate the camera vertically,
    // which is akin to moving your head up or down.
    // Example: myCamera.rotateVertCamera(90.0f) in effect causes the camera to
    // look directly "up" from its current vertical position.
    // Strategy: Function Composition
    void rotateVertCamera(float angleDegrees);
    
    // float -> void
    // EFFECT: Given a float angle in degrees rotate the camera horizontally,
    // which is akin to moving your head left or right.
    // Example: myCamera.rotateHorzCamera(90.0f) in effect causes the camera to
    // look directly "right" from its current horizontal position.
    // Strategy: Function Composition
    void rotateHorzCamera(float angleDegrees);
    
private:
    
    Vector3f yAxis;
    Vector3f pos;
    Vector3f forward;
    Vector3f up;
    Vector3f left;
    Vector3f right;
};
