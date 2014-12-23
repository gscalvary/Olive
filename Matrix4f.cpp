//
//  Matrix4f.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//

#include "Matrix4f.h"

Matrix4f::Matrix4f() {
    
    for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 4; ++j) {
            m[i][j] = 0.0;
        }
    }
}

float Matrix4f::getEntryMatrix4f(unsigned i, unsigned j) {
    
    if (i >= 4 || j >= 4) {
        return 0.0;
    }
    
    return m[i][j];
}

void Matrix4f::setEntryMatrix4f(unsigned i, unsigned j, float newValue) {
    
    if (i >= 4 || j >= 4) {
        return;
    }
    
    m[i][j] = newValue;
}

void Matrix4f::setIdentityMatrix4f() {
    
    m[0][0] = 1.0f;    m[0][1] = 0.0f;   m[0][2] = 0.0f;   m[0][3] = 0.0f;
    m[1][0] = 0.0f;    m[1][1] = 1.0f;   m[1][2] = 0.0f;   m[1][3] = 0.0f;
    m[2][0] = 0.0f;    m[2][1] = 0.0f;   m[2][2] = 1.0f;   m[2][3] = 0.0f;
    m[3][0] = 0.0f;    m[3][1] = 0.0f;   m[3][2] = 0.0f;   m[3][3] = 1.0f;
}

void Matrix4f::setTranslationMatrix4f(float x, float y, float z) {
    
    m[0][0] = 1.0f;    m[0][1] = 0.0f;   m[0][2] = 0.0f;   m[0][3] = x;
    m[1][0] = 0.0f;    m[1][1] = 1.0f;   m[1][2] = 0.0f;   m[1][3] = y;
    m[2][0] = 0.0f;    m[2][1] = 0.0f;   m[2][2] = 1.0f;   m[2][3] = z;
    m[3][0] = 0.0f;    m[3][1] = 0.0f;   m[3][2] = 0.0f;   m[3][3] = 1.0f;
}

void Matrix4f::setRotationMatrix4f(float x, float y, float z) {
    
    Matrix4f rx;
    Matrix4f ry;
    Matrix4f rz;
    
    // convert degrees to radians
    x = (float)(x * piD / 180.0f);
    y = (float)(y * piD / 180.0f);
    z = (float)(z * piD / 180.0f);
    
    // rotate about the z axis, x and y components are therefore changed
    rz.m[0][0] = cos(z);    rz.m[0][1] = -sin(z);   rz.m[0][2] = 0.0f;      rz.m[0][3] = 0.0f;
    rz.m[1][0] = sin(z);    rz.m[1][1] = cos(z);    rz.m[1][2] = 0.0f;      rz.m[1][3] = 0.0f;
    rz.m[2][0] = 0.0f;      rz.m[2][1] = 0.0f;      rz.m[2][2] = 1.0f;      rz.m[2][3] = 0.0f;
    rz.m[3][0] = 0.0f;      rz.m[3][1] = 0.0f;      rz.m[3][2] = 0.0f;      rz.m[3][3] = 1.0f;
    
    // rotate about the x axis, y and z components are therefore changed
    rx.m[0][0] = 1.0f;      rx.m[0][1] = 0.0f;      rx.m[0][2] = 0.0f;      rx.m[0][3] = 0.0f;
    rx.m[1][0] = 0.0f;      rx.m[1][1] = cos(x);    rx.m[1][2] = -sin(x);   rx.m[1][3] = 0.0f;
    rx.m[2][0] = 0.0f;      rx.m[2][1] = sin(x);    rx.m[2][2] = cos(x);    rx.m[2][3] = 0.0f;
    rx.m[3][0] = 0.0f;      rx.m[3][1] = 0.0f;      rx.m[3][2] = 0.0f;      rx.m[3][3] = 1.0f;
    
    // rotate about the y axis, x and z components are therefore changed
    ry.m[0][0] = cos(y);    ry.m[0][1] = 0.0f;      ry.m[0][2] = -sin(y);   ry.m[0][3] = 0.0f;
    ry.m[1][0] = 0.0f;      ry.m[1][1] = 1.0f;      ry.m[1][2] = 0.0f;      ry.m[1][3] = 0.0f;
    ry.m[2][0] = sin(y);    ry.m[2][1] = 0.0f;      ry.m[2][2] = cos(y);    ry.m[2][3] = 0.0f;
    ry.m[3][0] = 0.0f;      ry.m[3][1] = 0.0f;      ry.m[3][2] = 0.0f;      ry.m[3][3] = 1.0f;
    
    // order of operations matters here rx * ry stores result in ry
    //                                  ry * rz stores result in rz
    ry.multMatrix4f(&rx);
    rz.multMatrix4f(&ry);
    
    // set the values of this matrix to the final computed values in rz
    for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 4; ++j) {
            setEntryMatrix4f(i, j, rz.getEntryMatrix4f(i, j));
        }
    }
}

void Matrix4f::setScaleMatrix4f(float x, float y, float z) {
    
    m[0][0] = x;       m[0][1] = 0.0f;   m[0][2] = 0.0f;   m[0][3] = 0.0f;
    m[1][0] = 0.0f;    m[1][1] = y;      m[1][2] = 0.0f;   m[1][3] = 0.0f;
    m[2][0] = 0.0f;    m[2][1] = 0.0f;   m[2][2] = z;      m[2][3] = 0.0f;
    m[3][0] = 0.0f;    m[3][1] = 0.0f;   m[3][2] = 0.0f;   m[3][3] = 1.0f;
}

void Matrix4f::setProjectionMatrix4f(float zNear, float zFar, float width,
                                     float height,
                                     float fov) {
    
    // convert fov to radians
    fov = (float)(fov * piD / 180.0f);
    float tanHalfFov = tan(fov / 2);
    float zRange = zNear - zFar;
    float aspectRatio = width/height;
    
    m[0][0] = 1.0f / (tanHalfFov * aspectRatio);
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;
    
    m[1][0] = 0.0f;
    m[1][1] = 1.0f / tanHalfFov;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;
    
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = (-zNear - zFar) / zRange;
    m[2][3] = 2.0f * zFar * zNear / zRange;
    
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 1.0f;
    m[3][3] = 0.0f;
}

void Matrix4f::setCameraMatrix4f(Vector3f forward, Vector3f up) {
    
    Vector3f f(forward.getVector3fX(),
               forward.getVector3fY(),
               forward.getVector3fZ());
    f.normalizeVector3f();
    
    Vector3f r(up.getVector3fX(), up.getVector3fY(), up.getVector3fZ());
    r.normalizeVector3f();
    r.crossProductVector3f(f);
    
    Vector3f u(f.getVector3fX(), f.getVector3fY(), f.getVector3fZ());
    u.crossProductVector3f(r);
    
    m[0][0] = r.getVector3fX(); m[0][1] = r.getVector3fY(); m[0][2] = r.getVector3fZ(); m[0][3] = 0.0f;
    m[1][0] = u.getVector3fX(); m[1][1] = u.getVector3fY(); m[1][2] = u.getVector3fZ(); m[1][3] = 0.0f;
    m[2][0] = f.getVector3fX(); m[2][1] = f.getVector3fY(); m[2][2] = f.getVector3fZ(); m[2][3] = 0.0f;
    m[3][0] = 0.0f;             m[3][1] = 0.0f;             m[3][2] = 0.0f;             m[3][3] = 1.0f;
}

void Matrix4f::multMatrix4f(Matrix4f* n) {
    
    Matrix4f temp;
    
    for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 4; ++j) {
            temp.setEntryMatrix4f(i, j, m[i][0] * n->getEntryMatrix4f(0, j) +
                                        m[i][1] * n->getEntryMatrix4f(1, j) +
                                        m[i][2] * n->getEntryMatrix4f(2, j) +
                                        m[i][3] * n->getEntryMatrix4f(3, j));
        }
    }
    
    for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 4; ++j) {
            setEntryMatrix4f(i, j, temp.getEntryMatrix4f(i, j));
        }
    }
}
