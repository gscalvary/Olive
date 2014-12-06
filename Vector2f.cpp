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