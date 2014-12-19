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
    scale = new Vector3f(1.0f, 1.0f, 1.0f);
    translation = new Vector3f();
    rotationMatrix = new Matrix4f();
    scaleMatrix = new Matrix4f();
    translationMatrix = new Matrix4f();
}

Transform::~Transform() {
    
    delete rotation;
    delete scale;
    delete translation;
    delete rotationMatrix;
    delete scaleMatrix;
    delete translationMatrix;
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

Vector3f* Transform::getScalePtr() {
    
    return scale;
}

void Transform::setScale(Vector3f& scaleAddress) {
    
    scale = &scaleAddress;
}

void Transform::setScale(float x, float y, float z) {
    
    scale->setVector3fX(x);
    scale->setVector3fY(y);
    scale->setVector3fZ(z);
}

Matrix4f* Transform::getTransformationPtr() {
    
    rotationMatrix->setRotationMatrix4f(rotation->getVector3fX(),
                                        rotation->getVector3fY(),
                                        rotation->getVector3fZ());
    scaleMatrix->setScaleMatrix4f(scale->getVector3fX(),
                                  scale->getVector3fY(),
                                  scale->getVector3fZ());
    translationMatrix->setTranslationMatrix4f(translation->getVector3fX(),
                                              translation->getVector3fY(),
                                              translation->getVector3fZ());
    
    // multiply the rotation matrix by the scale matrix storing the
    // result in the rotation matrix
    rotationMatrix->multMatrix4f(scaleMatrix);
    
    // multiply the translation matrix by the rotation matrix storing the
    // result in the translation matrix
    translationMatrix->multMatrix4f(rotationMatrix);
    
    return translationMatrix;
}
