//
//  Quaternion.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//

#include "Quaternion.h"

Quaternion::Quaternion(float x, float y, float z, float w) {
    
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float Quaternion::getXQuaternion() {
    
    return x;
}

float Quaternion::getYQuaternion() {
    
    return y;
}

float Quaternion::getZQuaternion() {
    
    return z;
}

float Quaternion::getWQuaternion() {
    
    return w;
}

void Quaternion::setXQuaternion(float x) {
    
    this->x = x;
}

void Quaternion::setYQuaternion(float y) {
    
    this->y = y;
}

void Quaternion::setZQuaternion(float z) {
    
    this->z = z;
}

void Quaternion::setWQuaternion(float w) {
    
    this->w = w;
}

float Quaternion::lengthQuaternion() {
    
    return (float)sqrtf(x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::normalizeQuaternion() {
    
    float length = lengthQuaternion();
    x /= length;
    y /= length;
    z /= length;
    w /= length;
    
    return *this;
}

Quaternion Quaternion::conjugateQuaternion() {
    
    return *new Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::multQuaternion(Quaternion otherQuaternion) {
    
    float newW = w * otherQuaternion.getWQuaternion() - x * otherQuaternion.getXQuaternion() - y * otherQuaternion.getYQuaternion() - z * otherQuaternion.getZQuaternion();
    float newX = x * otherQuaternion.getWQuaternion() + w * otherQuaternion.getXQuaternion() + y * otherQuaternion.getZQuaternion() - z * otherQuaternion.getYQuaternion();
    float newY = y * otherQuaternion.getWQuaternion() + w * otherQuaternion.getYQuaternion() + z * otherQuaternion.getXQuaternion() - x * otherQuaternion.getZQuaternion();
    float newZ = z * otherQuaternion.getWQuaternion() + w * otherQuaternion.getZQuaternion() + x * otherQuaternion.getYQuaternion() - y * otherQuaternion.getXQuaternion();
    
    return *new Quaternion(newX, newY, newZ, newW);
}

Quaternion Quaternion::multQuaternion(Vector3f vector) {
    
    float newW = -x * vector.getVector3fX() - y * vector.getVector3fY() - z * vector.getVector3fZ();
    float newX =  w * vector.getVector3fX() + y * vector.getVector3fZ() - z * vector.getVector3fY();
    float newY =  w * vector.getVector3fY() + z * vector.getVector3fX() - x * vector.getVector3fZ();
    float newZ =  w * vector.getVector3fZ() + x * vector.getVector3fY() - y * vector.getVector3fX();
    
    return *new Quaternion(newX, newY, newZ, newW);
}
