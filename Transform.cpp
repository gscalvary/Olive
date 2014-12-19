//
//  Transform.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/17/14.
//
//

#include "Transform.h"

Transform::Transform() {
    
    rotation = new Vector3f();
    translation = new Vector3f();
    rotationMatrix = new Matrix4f();
    translationMatrix = new Matrix4f();
    resultMatrix = new Matrix4f();
}

Transform::~Transform() {
    
    delete rotation;
    delete translation;
    delete rotationMatrix;
    delete translationMatrix;
    delete resultMatrix;
}

Vector3f* Transform::getTranslationPtr() {
    
    return translation;
}

void Transform::setTranslation(Vector3f& translationAddress) {
    
    translation = &translationAddress;
}

void Transform::setTranslation(float x, float y, float z) {
    
    translation->setVector3fX(x);
    translation->setVector3fY(y);
    translation->setVector3fZ(z);
}

Vector3f* Transform::getRotationPtr() {
    
    return rotation;
}

void Transform::setRotation(Vector3f& rotationAddress) {
    
    rotation = &rotationAddress;
}

void Transform::setRotation(float x, float y, float z) {
    
    rotation->setVector3fX(x);
    rotation->setVector3fY(y);
    rotation->setVector3fZ(z);
}

Matrix4f* Transform::getTransformationPtr() {
    
    rotationMatrix->setTranslationMatrix4f(rotation->getVector3fX(),
                                           rotation->getVector3fY(),
                                           rotation->getVector3fZ());
    translationMatrix->setTranslationMatrix4f(translation->getVector3fX(),
                                              translation->getVector3fY(),
                                              translation->getVector3fZ());
    // multiply the translation matrix by the rotation matrix storing the
    // result in the translation matrix
    translationMatrix->multMatrix4f(rotationMatrix);
    
    return translationMatrix;
}
