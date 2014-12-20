//
//  Vector3f.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//

#include "Vector3f.h"

Vector3f::Vector3f() {
    
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3f::Vector3f(float x, float y, float z) {
    
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3f::getVector3fX() {
    
    return x;
}

float Vector3f::getVector3fY() {
    
    return y;
}

float Vector3f::getVector3fZ() {
    
    return z;
}

void Vector3f::setVector3fX(float x) {
    
    this->x = x;
}

void Vector3f::setVector3fY(float y) {
    
    this->y = y;
}

void Vector3f::setVector3fZ(float z) {
    
    this->z = z;
}

std::string Vector3f::reportVector3f() {
    
    std::ostringstream ostr;
    ostr << "(" << x << ", " << y << ", " << z << ")";
    std::string s = ostr.str();
    
    return s;
}

float Vector3f::lengthVector3f() {
    
    return (float)sqrtf(x * x + y * y + z * z);
}

float Vector3f::dotProductVector3f(Vector3f otherVector) {
    
    return (x * otherVector.getVector3fX() +
            y * otherVector.getVector3fY() +
            z * otherVector.getVector3fZ());
}

Vector3f Vector3f::crossProductVector3f(Vector3f otherVector) {
    
    float newX = y * otherVector.getVector3fZ() - z * otherVector.getVector3fY();
    float newY = z * otherVector.getVector3fX() - x * otherVector.getVector3fZ();
    float newZ = x * otherVector.getVector3fY() - y * otherVector.getVector3fX();
    
    return *new Vector3f(newX, newY, newZ);
}

void Vector3f::normalizeVector3f() {
    
    float length = lengthVector3f();
    x /= length;
    y /= length;
    z /= length;
}

Vector3f Vector3f::rotateVector3f(float angle) {
    
    //double rad = angle * piD / 180.0;
    //double cosRad = cos(rad);
    //double sinRad = sin(rad);
    
    return *this;
}

Vector3f Vector3f::addVector3f(Vector3f otherVector) {
    
    return *new Vector3f(x + otherVector.getVector3fX(),
                         y + otherVector.getVector3fY(),
                         z + otherVector.getVector3fZ());
}

Vector3f Vector3f::addVector3f(float scalar) {
    
    return *new Vector3f(x + scalar, y + scalar, z + scalar);
}

Vector3f Vector3f::subVector3f(Vector3f otherVector) {
    
    return *new Vector3f(x - otherVector.getVector3fX(),
                         y - otherVector.getVector3fY(),
                         z - otherVector.getVector3fZ());
}

Vector3f Vector3f::subVector3f(float scalar) {
    
    return *new Vector3f(x - scalar, y - scalar, z - scalar);
}

Vector3f Vector3f::multVector3f(Vector3f otherVector) {
    
    return *new Vector3f(x * otherVector.getVector3fX(),
                         y * otherVector.getVector3fY(),
                         z * otherVector.getVector3fZ());
}

Vector3f Vector3f::multVector3f(float scalar) {
    
    return *new Vector3f(x * scalar, y * scalar, z * scalar);
}

Vector3f Vector3f::divVector3f(Vector3f otherVector) {
    
    if (otherVector.getVector3fX() == 0.0 ||
        otherVector.getVector3fY() == 0.0 ||
        otherVector.getVector3fZ() == 0.0) {
        return *this;
    } else {
        return *new Vector3f(x / otherVector.getVector3fX(),
                             y / otherVector.getVector3fY(),
                             z / otherVector.getVector3fZ());
    }
}

Vector3f Vector3f::divVector3f(float scalar) {
    
    if (scalar == 0.0) {
        return *this;
    } else {
        return *new Vector3f(x / scalar, y / scalar, z / scalar);
    }
}
