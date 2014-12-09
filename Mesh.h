//
//  Mesh.h
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//

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
    // Example: addVerticesMesh(myVerticesVector)
    // Strategy: Function Composition
    void addVerticesMesh(std::vector<Vertex*> vertices);
    
    //  -> void
    // Submit the mesh to OpenGL for drawing.
    // Example: drawMesh();
    // Strategy: Function Composition
    void drawMesh();
    
private:
    
    int numVertexPosCoords;
    unsigned bufferIds[1];
    unsigned vertexVboId;
    float buffer[];
};