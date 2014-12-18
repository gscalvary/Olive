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
    
    m[0][0] = 1.0;    m[0][1] = 0.0;   m[0][2] = 0.0;   m[0][3] = 0.0;
    m[1][0] = 0.0;    m[1][1] = 1.0;   m[1][2] = 0.0;   m[1][3] = 0.0;
    m[2][0] = 0.0;    m[2][1] = 0.0;   m[2][2] = 1.0;   m[2][3] = 0.0;
    m[3][0] = 0.0;    m[3][1] = 0.0;   m[3][2] = 0.0;   m[3][3] = 1.0;
}

void Matrix4f::setTranslationMatrix4f(float x, float y, float z) {
    
    m[0][0] = 1.0;    m[0][1] = 0.0;   m[0][2] = 0.0;   m[0][3] = x;
    m[1][0] = 0.0;    m[1][1] = 1.0;   m[1][2] = 0.0;   m[1][3] = y;
    m[2][0] = 0.0;    m[2][1] = 0.0;   m[2][2] = 1.0;   m[2][3] = z;
    m[3][0] = 0.0;    m[3][1] = 0.0;   m[3][2] = 0.0;   m[3][3] = 1.0;
}

Matrix4f Matrix4f::multMatrix4f(Matrix4f n) {
    
    Matrix4f* res = new Matrix4f();
    
    for (unsigned i; i < 4; ++i) {
        for (unsigned j; j < 4; ++j) {
            res->setEntryMatrix4f(i, j,
                                  m[i][0] * n.getEntryMatrix4f(0, j) +
                                  m[i][1] * n.getEntryMatrix4f(1, j) +
                                  m[i][2] * n.getEntryMatrix4f(2, j) +
                                  m[i][3] * n.getEntryMatrix4f(3, j));
        }
    }
    
    return *res;
}