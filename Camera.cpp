//
//  Camera.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/22/14.
//
//

#include "Camera.h"

Camera::Camera() {
    
    pos.setVector3fX(0.0f);
    pos.setVector3fY(0.0f);
    pos.setVector3fZ(0.0f);
    
    forward.setVector3fX(0.0f);
    forward.setVector3fY(0.0f);
    forward.setVector3fZ(1.0f);
    
    up.setVector3fX(0.0f);
    up.setVector3fY(1.0f);
    up.setVector3fZ(0.0f);
    
    yAxis.setVector3fX(0.0f);
    yAxis.setVector3fY(1.0f);
    yAxis.setVector3fZ(0.0f);
}

Camera::Camera(Vector3f pos, Vector3f forward, Vector3f up) {
    
    this->pos.setVector3fX(pos.getVector3fX());
    this->pos.setVector3fY(pos.getVector3fY());
    this->pos.setVector3fZ(pos.getVector3fZ());
    
    this->forward.setVector3fX(forward.getVector3fX());
    this->forward.setVector3fY(forward.getVector3fY());
    this->forward.setVector3fZ(forward.getVector3fZ());
    this->forward.normalizeVector3f();
    
    this->up.setVector3fX(up.getVector3fX());
    this->up.setVector3fY(up.getVector3fY());
    this->up.setVector3fZ(up.getVector3fZ());
    this->up.normalizeVector3f();
    
    yAxis.setVector3fX(0.0f);
    yAxis.setVector3fY(1.0f);
    yAxis.setVector3fZ(0.0f);
}

Vector3f* Camera::getPosCamera() {
    
    return &pos;
}

void Camera::setPosCamera(Vector3f* newPos) {
    
    this->pos.setVector3fX(newPos->getVector3fX());
    this->pos.setVector3fY(newPos->getVector3fY());
    this->pos.setVector3fZ(newPos->getVector3fZ());
}

Vector3f* Camera::getForwardCamera() {
    
    return &forward;
}

void Camera::setForwardCamera(Vector3f* newForward) {
    
    this->forward.setVector3fX(newForward->getVector3fX());
    this->forward.setVector3fY(newForward->getVector3fY());
    this->forward.setVector3fZ(newForward->getVector3fZ());
}

Vector3f* Camera::getUpCamera() {
    
    return &up;
}

void Camera::setUpCamera(Vector3f* newUp) {
    
    this->up.setVector3fX(newUp->getVector3fX());
    this->up.setVector3fY(newUp->getVector3fY());
    this->up.setVector3fZ(newUp->getVector3fZ());
}

Vector3f* Camera::getLeftCamera() {
    
    left.setVector3fX(forward.getVector3fX());
    left.setVector3fY(forward.getVector3fY());
    left.setVector3fZ(forward.getVector3fZ());
    
    left.crossProductVector3f(up);
    left.normalizeVector3f();
    
    return &left;
}

Vector3f* Camera::getRightCamera() {
    
    right.setVector3fX(up.getVector3fX());
    right.setVector3fY(up.getVector3fY());
    right.setVector3fZ(up.getVector3fZ());
    
    right.crossProductVector3f(forward);
    right.normalizeVector3f();
    
    return &right;
}

void Camera::moveCamera(Vector3f dir, float amt) {
    
    // multiply the direction vector by the amount
    dir.multVector3f(amt);
    
    // add the modified direction vector to the camera's position vector
    pos.addVector3f(dir);
}

void Camera::rotateVertCamera(float angleDegrees) {
    
    // compute the horizontal axis
    Vector3f hAxis(yAxis.getVector3fX(),
                   yAxis.getVector3fY(),
                   yAxis.getVector3fZ());
    hAxis.crossProductVector3f(forward);
    hAxis.normalizeVector3f();
    
    // modify the forward vector
    forward.rotateVector3f(angleDegrees, hAxis);
    forward.normalizeVector3f();
    
    // modify the up vector
    up.setVector3fX(forward.getVector3fX());
    up.setVector3fY(forward.getVector3fY());
    up.setVector3fZ(forward.getVector3fZ());
    up.crossProductVector3f(hAxis);
    up.normalizeVector3f();
}

void Camera::rotateHorzCamera(float angleDegrees) {
    
    // compute the horizontal axis
    Vector3f hAxis(yAxis.getVector3fX(),
                   yAxis.getVector3fY(),
                   yAxis.getVector3fZ());
    hAxis.crossProductVector3f(forward);
    hAxis.normalizeVector3f();
    
    // modify the forward vector
    forward.rotateVector3f(angleDegrees, yAxis);
    forward.normalizeVector3f();
    
    // modify the up vector
    up.setVector3fX(forward.getVector3fX());
    up.setVector3fY(forward.getVector3fY());
    up.setVector3fZ(forward.getVector3fZ());
    up.crossProductVector3f(hAxis);
    up.normalizeVector3f();
}
