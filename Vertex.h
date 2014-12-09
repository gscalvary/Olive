//
//  Vertex.h
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//

#ifndef __Olive__Vertex__
#define __Olive__Vertex__

#include <stdio.h>
#include "Vector3f.h"

#endif /* defined(__Olive__Vertex__) */

class Vertex {
public:
    
    // Vector3f -> Vertex*
    // Given a Vector3f* construct a Vertex object.
    // Example: Vector3f* myVector3f = new Vector3f(1.0, 1.0, 1.0);
    //          Vertex(myVector3f) builds a Vertex with pos = to the passed
    //          in Vector3f.
    // Strategy: Domain Knowledge
    Vertex(Vector3f* pos);
    
    //  -> Vector3f*
    // Return a pointer to the pos of the Vertex.
    // Example: getPosVertex() returns pos;
    // Strategy: Domain Knowledge
    Vector3f* getPosVertex();
    
    // Vector3f* -> void
    // Sets the pointer for the pos of the Vertex to the passed in Vector3f.
    // Example: setPosVertex(Vector3f* newPos) sets pos to newPos;
    // Strategy: Domain Knowledge
    void setPosVertex(Vector3f* newPos);
    
    //  -> int
    // Return the size of the Vertex, that is how many coordinates there are
    // to its pos.
    // Example: getSizeVertex() returns size;
    // Strategy: Domain Knowledge
    int getSizeVertex();
    
private:
    
    Vector3f* pos;
    const int size = 3;
};