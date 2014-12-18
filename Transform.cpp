//
//  Transform.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/17/14.
//
//

#include "Transform.h"

Transform::Transform() {
    
    translation = new Vector3f();
    transformation = new Matrix4f();
}

Transform::~Transform() {
    
    delete translation;
    delete transformation;
}

Vector3f* Transform::getTranslationPtr() {
    
    return translation;
}

Matrix4f* Transform::getTransformationPtr() {
    
    transformation->setTranslationMatrix4f(translation->getVector3fX(),
                                           translation->getVector3fY(),
                                           translation->getVector3fZ());
    return transformation;
}

void Transform::setTranslation(Vector3f& translationAddress) {
    
    translation = &translationAddress;
}

void Transform::setTranslation(float x, float y, float z) {
    
    translation->setVector3fX(x);
    translation->setVector3fY(y);
    translation->setVector3fZ(z);
}