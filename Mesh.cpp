//
//  Mesh.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//

#include "Mesh.h"

Mesh::Mesh() {

    numVertex = 0.0l;
    numVertexPosCoords = 0;
}

void Mesh::addVerticesMesh(std::vector<Vertex*> vertices) {
    
    if (vertices.size() > 0) {
        numVertex = vertices.size();
        numVertexPosCoords = vertices[0]->getSizeVertex();
    } else {
        return;
    }
    
    // add the vertices position coordinates to the buffer
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
    
    if (index >= numVertex * numVertexPosCoords) {
        return 0.0f;
    } else {
        return buffer[index];
    }
}

void Mesh::drawMesh() {
    
    GLuint vertexVboId;
    // ask OpenGL for a buffer name for our vertex buffer
    glGenBuffers(1, &vertexVboId);
    // bind the returned buffer name to the GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, vertexVboId);
    // buffer the data writing it to storage on the graphics card
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(float) * numVertexPosCoords,
                 NULL,
                 GL_STATIC_DRAW);
    // obtain memory pointer on GPU
    void *ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    // copy data from my array of floats
    memcpy(ptr, buffer, sizeof(float) * numVertexPosCoords * numVertex);
    // copying complete
    glUnmapBuffer(GL_ARRAY_BUFFER);
    // allow the passing of array characteristics to OpenGL
    //glEnableVertexAttribArray(0);
    // specify the characteristics of the arrayed data
    //glVertexAttribPointer(0,
    //                      3,            // how many data points per vertex
    //                      GL_FLOAT,     // base type of data
    //                      GL_FALSE,
    //                      0,            // spacing between values
    //                      0);           // byte offset from the front of the
                                        //  buffer
    // draw the data
    //glDrawArrays(GL_TRIANGLES, 0, numVertexPosCoords);
    // disallow the passing of array characteristics to OpenGL
    //glDisableVertexAttribArray(0);
    // unbind the GL_ARRAY_BUFFER
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
}
