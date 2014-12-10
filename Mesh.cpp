//
//  Mesh.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//

#include "Mesh.h"

Mesh::Mesh() {

    numVertex = 0;
    numVertexPosCoords = 0;
    buffer = NULL;
}

Mesh::~Mesh() {
    
    // delete the memory allocated for the buffer
    delete[] buffer;
    buffer = NULL;
}

void Mesh::addVerticesMesh(std::vector<Vertex*> vertices) {
    
    // check there are vertices to add
    if (vertices.size() > 0) {
        numVertex = (unsigned)vertices.size();
        numVertexPosCoords = vertices[0]->getSizeVertex();
    } else {
        return;
    }
    
    // deallocate memory for the buffer if it is allocated already
    if (buffer != NULL) {
        delete[] buffer;
        buffer = NULL;
    }

    // add the vertices position coordinates to the buffer
    buffer = new GLfloat[(int)(numVertexPosCoords * numVertex)];
    int i = 0;
    for (int j = 0; j < vertices.size(); ++j) {
        buffer[i] = vertices[j]->getPosVertex()->getVector3fX();
        i += 1;
        buffer[i] = vertices[j]->getPosVertex()->getVector3fY();
        i += 1;
        buffer[i] = vertices[j]->getPosVertex()->getVector3fZ();
        i += 1;
    }
}

float Mesh::getBufferElementMesh(unsigned index) {
    
    if (index >= numVertex * numVertexPosCoords || buffer == NULL) {
        return 0.0f;
    } else {
        return buffer[index];
    }
}

void Mesh::drawMesh() {

    // enable and specify a pointer to the vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(numVertexPosCoords, GL_FLOAT, 0, buffer);
    // draw the vertices
    glDrawArrays(GL_TRIANGLES, 0, numVertexPosCoords * numVertex);
    // disable the pointer to the vertex array
    glDisableClientState(GL_VERTEX_ARRAY);
}
