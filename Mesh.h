//
//  Mesh.h
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//
# pragma once
#ifndef __Olive__Mesh__
#define __Olive__Mesh__

#include <iostream>
#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include "Vertex.h"

#endif /* defined(__Olive__Mesh__) */

class Mesh {
public:

    //  -> Mesh*
    // Constructor method for the Mesh class.
    // Example: Mesh() creates a Mesh object and returns a pointer to it.
    // Strategy: Function Composition
    Mesh();
    
    //  -> void
    // Destructor method for the Mesh class.
    // Example: ~Mesh() deletes a Mesh object.
    // Strategy: Function Composition
    ~Mesh();
    
    // vector vector -> void
    // Given a vector of vertex pointers and a vector of GLubyte indices process
    // the data.
    // INVARIANT: the vector of vertex pointers must contain at least one vertex
    //            the vector of GLubyte indices must contain at least three
    //            entries (one triangle)
    // Example: addVerticesMesh(myVerticesVector, myIndexVector)
    // Strategy: Function Composition
    void addVerticesMesh(std::vector<Vertex*> vertices,
                         std::vector<GLubyte> indices);
    
    //  -> void
    // Submit the mesh to OpenGL for drawing.
    // Example: drawMesh();
    // Strategy: Function Composition
    void drawMesh();
    
    // unsigned -> float
    // Given an unsigned int as an index, return the float associated with the
    // index from the mesh vbo buffer.
    // INVARIANT: unsigned < numVertex * numVertexPosCoords
    // Example: getVboBufferElementMesh(0);
    // Strategy: Function Composition
    float getVboBufferElementMesh(unsigned index);
    
    // unsigned -> int
    // Given an unsigned int as an index, return the int associated with the
    // index from the mesh ibo buffer.
    // INVARIANT: unsigned < number of elements in the ibo buffer
    // Example: getIboBufferElementMesh(0);
    // Strategy: Function Composition
    int getIboBufferElementMesh(unsigned index);
    
private:
    
    unsigned numVertex;
    unsigned numVertexPosCoords;
    unsigned numIndices;
    GLubyte* iboBuffer;
    GLfloat* vboBuffer;
};