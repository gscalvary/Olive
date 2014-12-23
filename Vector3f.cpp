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

void Vector3f::crossProductVector3f(Vector3f otherVector) {
    
    // use the original values in the below computation or the computation's
    // later equations will use the result of the earlier equations
    float xO = x;
    float yO = y;
    float zO = z;
    
    x = yO * otherVector.getVector3fZ() - zO * otherVector.getVector3fY();
    y = zO * otherVector.getVector3fX() - xO * otherVector.getVector3fZ();
    z = xO * otherVector.getVector3fY() - yO * otherVector.getVector3fX();
}

void Vector3f::normalizeVector3f() {
    
    float length = lengthVector3f();
    
    if (length == 0.0f) {
        return;
    }
    
    x /= length;
    y /= length;
    z /= length;
}

void Vector3f::rotateVector3f(float angle, Vector3f axis) {
    
    // convert angle to radians
    angle = (float)(angle * piD / 180.0f);
    
    float sinHalfAngle = sin(angle / 2.0f);
    float cosHalfAngle = cos(angle / 2.0f);
    
    float rX = axis.getVector3fX() * sinHalfAngle;
    float rY = axis.getVector3fY() * sinHalfAngle;
    float rZ = axis.getVector3fZ() * sinHalfAngle;
    float rW = cosHalfAngle;
    
    Quaternion rotation(rX, rY, rZ, rW);
    Quaternion conjugate(rX, rY, rZ, rW);
    conjugate.conjugateQuaternion();
    Quaternion vector(axis.getVector3fX(),
                      axis.getVector3fY(),
                      axis.getVector3fZ(),
                      0.0f);
    
    rotation.multQuaternion(conjugate);
    rotation.multQuaternion(vector);
    
    x = rotation.getXQuaternion();
    y = rotation.getYQuaternion();
    z = rotation.getZQuaternion();
}

void Vector3f::addVector3f(Vector3f otherVector) {
    
    x += otherVector.getVector3fX();
    y += otherVector.getVector3fY();
    z += otherVector.getVector3fZ();
}

void Vector3f::addVector3f(float scalar) {
    
    x += scalar;
    y += scalar;
    z += scalar;
}

void Vector3f::subVector3f(Vector3f otherVector) {
    
    x -= otherVector.getVector3fX();
    y -= otherVector.getVector3fY();
    z -= otherVector.getVector3fZ();
}

void Vector3f::subVector3f(float scalar) {
    
    x -= scalar;
    y -= scalar;
    z -= scalar;
}

void Vector3f::multVector3f(Vector3f otherVector) {
    
    x *= otherVector.getVector3fX();
    y *= otherVector.getVector3fY();
    z *= otherVector.getVector3fZ();
}

void Vector3f::multVector3f(float scalar) {
    
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void Vector3f::divVector3f(Vector3f otherVector) {
    
    if (otherVector.getVector3fX() == 0.0 ||
        otherVector.getVector3fY() == 0.0 ||
        otherVector.getVector3fZ() == 0.0) {
        return;
    } else {
        x /= otherVector.getVector3fX();
        y /= otherVector.getVector3fY();
        z /= otherVector.getVector3fZ();
    }
}

void Vector3f::divVector3f(float scalar) {
    
    if (scalar == 0.0) {
        return;
    } else {
        x /= scalar;
        y /= scalar;
        z /= scalar;
    }
}
