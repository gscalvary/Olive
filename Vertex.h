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
    // Given a Vector3f construct a Vertex object.
    // Example: Vertex((1.0, 1.0, 1.0)) builds a Vertex with pos = to the passed
    // in Vector3.
    // Strategy: Domain Knowledge
    Vertex(Vector3f pos);
    
    //  -> Vector3f
    // Return the pos of the Vertex.
    // Example: getPosVertex() returns pos;
    // Strategy: Domain Knowledge
    Vector3f getPosVertex();
    
    // Vector3f -> void
    // Sets the pos of the Vertex to the passed in Vector3f.
    // Example: setPosVertex(Vector3f newPos) sets pos to newPos;
    // Strategy: Domain Knowledge
    void setPosVertex(Vector3f newPos);
    
private:
    
    Vector3f* pos;
    const int size =3;
};