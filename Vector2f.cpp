//
//  Vector2f.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//

#include "Vector2f.h"

Vector2f::Vector2f() {
    
    x = 0.0;
    y = 0.0;
}

Vector2f::Vector2f(float x, float y) {
    
    this->x = x;
    this->y = y;
}

float Vector2f::getVector2fX() {
    
    return x;
}

float Vector2f::getVector2fY() {
    
    return y;
}

void Vector2f::setVector2fX(float x) {
    
    this->x = x;
}

void Vector2f::setVector2fY(float y) {
    
    this->y = y;
}

std::string Vector2f::reportVector2f() {
    
    std::ostringstream ostr;
    ostr << "(" << x << ", " << y << ")";
    std::string s = ostr.str();
    
    return s;
}

float Vector2f::lengthVector2f() {
    
    return (float)sqrtf(x * x + y * y);
}

float Vector2f::dotProductVector2f(Vector2f otherVector) {
    
    return (x * otherVector.getVector2fX() + y * otherVector.getVector2fY());
}

Vector2f Vector2f::normalizeVector2f() {
    
    float length = lengthVector2f();
    x /= length;
    y /= length;
    
    return *this;
}

Vector2f Vector2f::rotateVector2f(float angle) {
    
    double rad = angle * piD / 180.0;
    double cosRad = cos(rad);
    double sinRad = sin(rad);
    
    return *new Vector2f((float)(x * cosRad - y * sinRad),
                         (float)(x * sinRad + y * cosRad));
}

Vector2f Vector2f::addVector2f(Vector2f otherVector) {
    
    return *new Vector2f(x + otherVector.getVector2fX(),
                         y + otherVector.getVector2fY());
}

Vector2f Vector2f::addVector2f(float scalar) {
    
    return *new Vector2f(x + scalar, y + scalar);
}

Vector2f Vector2f::subVector2f(Vector2f otherVector) {
    
    return *new Vector2f(x - otherVector.getVector2fX(),
                         y - otherVector.getVector2fY());
}

Vector2f Vector2f::subVector2f(float scalar) {
    
    return *new Vector2f(x - scalar, y - scalar);
}

Vector2f Vector2f::multVector2f(Vector2f otherVector) {
    
    return *new Vector2f(x * otherVector.getVector2fX(),
                         y * otherVector.getVector2fY());
}

Vector2f Vector2f::multVector2f(float scalar) {
    
    return *new Vector2f(x * scalar, y * scalar);
}

Vector2f Vector2f::divVector2f(Vector2f otherVector) {
    
    if (otherVector.getVector2fX() == 0.0 ||
        otherVector.getVector2fY() == 0.0) {
        return *this;
    } else {
        return *new Vector2f(x / otherVector.getVector2fX(),
                             y / otherVector.getVector2fY());
    }
}

Vector2f Vector2f::divVector2f(float scalar) {
    
    if (scalar == 0.0) {
        return *this;
    } else {
        return *new Vector2f(x / scalar, y / scalar);
    }
}
