//
//  Mesh.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//

#include "Mesh.h"

Mesh::Mesh() {

    numIndices = 0;
    numVertex = 0;
    numVertexPosCoords = 0;
    iboBuffer = NULL;
    vboBuffer = NULL;
}

Mesh::~Mesh() {
    
    // delete the memory allocated for the buffers
    delete[] iboBuffer;
    delete[] vboBuffer;
}

void Mesh::addVerticesMesh(std::vector<Vertex*> vertices,
                           std::vector<GLubyte> indices) {
    
    // check if there are vertices to add
    if (vertices.size() > 0) {
        numVertex = (unsigned)vertices.size();
        numVertexPosCoords = vertices[0]->getSizeVertex();
    } else {
        return;
    }
    // check if there are at least enough indices to draw a triangle
    if (indices.size() >= 3) {
        numIndices = (unsigned)indices.size();
    } else {
        return;
    }
    
    // deallocate memory for the vbo buffer if it is allocated already
    if (vboBuffer != NULL) {
        delete[] vboBuffer;
        vboBuffer = NULL;
    }
    // deallocate memory for the ibo buffer if it is allocated already
    if (iboBuffer != NULL) {
        delete[] iboBuffer;
        iboBuffer = NULL;
    }

    // add the vertices position coordinates to the vbo buffer
    vboBuffer = new GLfloat[(int)(numVertexPosCoords * numVertex)];
    int i = 0;
    for (int j = 0; j < vertices.size(); ++j) {
        vboBuffer[i] = vertices[j]->getPosVertex()->getVector3fX();
        i += 1;
        vboBuffer[i] = vertices[j]->getPosVertex()->getVector3fY();
        i += 1;
        vboBuffer[i] = vertices[j]->getPosVertex()->getVector3fZ();
        i += 1;
    }
    // add the indices data to the ibo buffer
    iboBuffer = new GLubyte[(int)(indices.size())];
    for (int j = 0; j < indices.size(); ++j) {
        iboBuffer[j] = indices[j];
    }
}

float Mesh::getVboBufferElementMesh(unsigned index) {
    
    if (index >= numVertex * numVertexPosCoords || vboBuffer == NULL) {
        return 0.0f;
    }
    
    return vboBuffer[index];
}

int Mesh::getIboBufferElementMesh(unsigned index) {
    
    if (iboBuffer == NULL) {
        return 0;
    }
    
    if (index >= sizeof(vboBuffer)/sizeof(vboBuffer[0])) {
        return 0;
    }
    
    return iboBuffer[index];
}

void Mesh::drawMesh() {

    // enable and specify a pointer to the vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(numVertexPosCoords, GL_FLOAT, 0, vboBuffer);
    // draw the vertices
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_BYTE, iboBuffer);
    // disable the pointer to the vertex array
    glDisableClientState(GL_VERTEX_ARRAY);
}
