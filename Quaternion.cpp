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
    
    w = w * otherQuaternion.getWQuaternion() - x * otherQuaternion.getXQuaternion() - y * otherQuaternion.getYQuaternion() - z * otherQuaternion.getZQuaternion();
    x = x * otherQuaternion.getWQuaternion() + w * otherQuaternion.getXQuaternion() + y * otherQuaternion.getZQuaternion() - z * otherQuaternion.getYQuaternion();
    y = y * otherQuaternion.getWQuaternion() + w * otherQuaternion.getYQuaternion() + z * otherQuaternion.getXQuaternion() - x * otherQuaternion.getZQuaternion();
    z = z * otherQuaternion.getWQuaternion() + w * otherQuaternion.getZQuaternion() + x * otherQuaternion.getYQuaternion() - y * otherQuaternion.getXQuaternion();
}
