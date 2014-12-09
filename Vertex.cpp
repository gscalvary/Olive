//
//  Vertex.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//

#include "Vertex.h"

Vertex::Vertex(Vector3f* pos) {
    
    this->pos.setVector3fX(pos->getVector3fX());
    this->pos.setVector3fY(pos->getVector3fY());
    this->pos.setVector3fZ(pos->getVector3fZ());
}

Vector3f* Vertex::getPosVertex() {
    
    return &pos;
}

void Vertex::setPosVertex(Vector3f* newPos) {
    
    this->pos.setVector3fX(newPos->getVector3fX());
    this->pos.setVector3fY(newPos->getVector3fY());
    this->pos.setVector3fZ(newPos->getVector3fZ());
}

int Vertex::getSizeVertex() {
    
    return size;
}