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
    
    // vector -> void
    // Given a vector of vertex pointers process the data.
    // INVARIANT: the vector of vertex pointers must contain at least one vertex
    // Example: addVerticesMesh(myVerticesVector)
    // Strategy: Function Composition
    void addVerticesMesh(std::vector<Vertex*> vertices);
    
    //  -> void
    // Submit the mesh to OpenGL for drawing.
    // Example: drawMesh();
    // Strategy: Function Composition
    void drawMesh();
    
    // unsigned -> float
    // Given an unsigned int as an index, return the float associated with the
    // index from the mesh buffer.
    // INVARIANT: unsigned < numVertex * numVertexPosCoords
    // Example: getBufferElementMesh(0);
    // Strategy: Function Composition
    float getBufferElementMesh(unsigned index);
    
private:
    
    unsigned long numVertex;
    int numVertexPosCoords;
    float buffer[];
};