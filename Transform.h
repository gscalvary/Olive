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
#include "Camera.h"
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
    // attributes to them.
    // Example: myTransform.setTranslation(0.0f, 1.0f, 2.0f); sets translation
    // x coordinate to 0.0f, y coordinate to 1.0f and z coordinate to 2.0f.
    // Strategy: Function Composition
    void setTranslation(float x, float y, float z);
    
    //  -> Vector3f*
    // Return a pointer to the rotation Vector3f of this Transform object.
    // Example: myTransform.getRotationPtr(); returns a pointer to
    // rotation.
    // Strategy: Domain Knowledge
    Vector3f* getRotationPtr();
    
    // Vector3f& -> void
    // Given an address of a Vector3f set this objects rotation to it.
    // Example: myTransform.setRotation(vector3f&); sets rotation to the
    // given address.
    // Strategy: Domain Knowledge
    void setRotation(Vector3f& rotationAddress);
    
    // float, float, float -> void
    // Given the x, y and z coordinates of a Vector3f set the rotation's
    // attributes to them.
    // Example: myTransform.setRotation(0.0f, 1.0f, 2.0f); sets rotation
    // x coordinate to 0.0f, y coordinate to 1.0f and z coordinate to 2.0f.
    // Strategy: Function Composition
    void setRotation(float x, float y, float z);
    
    //  -> Vector3f*
    // Return a pointer to the scale Vector3f of this Transform object.
    // Example: myTransform.getScalePtr(); returns a pointer to
    // scale.
    // Strategy: Domain Knowledge
    Vector3f* getScalePtr();
    
    // Vector3f& -> void
    // Given an address of a Vector3f set this objects scale to it.
    // Example: myTransform.setScale(vector3f&); sets scale to the
    // given address.
    // Strategy: Domain Knowledge
    void setScale(Vector3f& scaleAddress);
    
    // float, float, float -> void
    // Given the x, y and z coordinates of a Vector3f set the scale's
    // attributes to them.
    // Example: myTransform.setScale(0.0f, 1.0f, 2.0f); sets scale
    // x coordinate to 0.0f, y coordinate to 1.0f and z coordinate to 2.0f.
    // Strategy: Function Composition
    void setScale(float x, float y, float z);
    
    //  -> Matrix4f*
    // Return a pointer to the transformation matrix.
    // EFFECT: transforms the matrix by the translation vector.
    // Example: myTransform.getTransformationPtr(); returns a pointer to the
    // transformation matrix.
    // Strategy: Function Composition
    Matrix4f* getTransformationPtr();
    
    //  -> Matrix4f*
    // Return a pointer to a projected transformation matrix.
    // EFFECT: applies a projection to the transformation matrix.
    // Example: myTransform.getProjectedTransformationPtr(); returns a pointer
    // to the projected transformation matrix.
    // Strategy: Function Composition
    Matrix4f* getProjectedTransformationPtr();
    
    // float, float, float, float, float -> void
    // Given the zNear, zFar, width of the screen, height of the screen and
    // field of view angle set the transforms projection attributes to them.
    // Example: myTransform.setProjection(0.1f, 1.0f, 800.0f, 600.0f, 270.0f);
    // sets: zNear = 0.1f
    //       zFar = 1.0f
    //       width = 800.0f
    //       height = 600.0f
    //       fov = 270.0f
    // Strategy: Domain Knowledge
    void setProjection(float zNear, float zFar, float width, float height, float fov);
    
    //  -> Camera*
    // Returns a pointer to the Transforms camera.
    // Example: myTransform.getCameraTransformPtr();
    // Strategy: Domain Knowledge
    Camera* getCameraTransformPtr();
    
    // Camera* -> void
    // EFFECT: Given a pointer to a camera set this transforms camera pointer to
    // it's attributes.
    // Example: myTransform->setCameraTransform(myCameraPtr);
    // Domain Knowledge
    void setCameraTransform(Camera* cameraPtr);
    
private:
    
    float zNear;
    float zFar;
    float width;
    float height;
    // degrees
    float fov;
    
    Camera tCamera;
    
    Vector3f* rotation;
    Vector3f* scale;
    Vector3f* translation;
    
    Matrix4f* cameraRotationMatrix;
    Matrix4f* cameraTranslationMatrix;
    Matrix4f* projectionMatrix;
    Matrix4f* rotationMatrix;
    Matrix4f* scaleMatrix;
    Matrix4f* translationMatrix;
};
