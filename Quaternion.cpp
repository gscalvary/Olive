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

void Quaternion::normalizeQuaternion() {
    
    float length = lengthQuaternion();
    x /= length;
    y /= length;
    z /= length;
    w /= length;
}

void Quaternion::conjugateQuaternion() {
    
    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

void Quaternion::multQuaternion(Quaternion otherQuaternion) {
    
    // use the original values in the below computation or the computation's
    // later equations will use the result of the earlier equations
    float xO = x;
    float yO = y;
    float zO = z;
    float wO = w;
    
    w = wO * otherQuaternion.getWQuaternion() - xO * otherQuaternion.getXQuaternion() - yO * otherQuaternion.getYQuaternion() - zO * otherQuaternion.getZQuaternion();
    x = xO * otherQuaternion.getWQuaternion() + wO * otherQuaternion.getXQuaternion() + yO * otherQuaternion.getZQuaternion() - zO * otherQuaternion.getYQuaternion();
    y = yO * otherQuaternion.getWQuaternion() + wO * otherQuaternion.getYQuaternion() + zO * otherQuaternion.getXQuaternion() - xO * otherQuaternion.getZQuaternion();
    z = zO * otherQuaternion.getWQuaternion() + wO * otherQuaternion.getZQuaternion() + xO * otherQuaternion.getYQuaternion() - yO * otherQuaternion.getXQuaternion();
}
