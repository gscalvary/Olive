//
//  Vertex.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//

#include "Vertex.h"

Vertex::Vertex(Vector3f pos) {
    
    this->pos = &pos;
}

Vector3f Vertex::getPosVertex() {
    
    return *pos;
}

void Vertex::setPosVertex(Vector3f newPos) {
    
    pos = &newPos;
}