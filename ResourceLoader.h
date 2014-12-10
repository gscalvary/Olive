//
//  ResourceLoader.h
//  Olive
//
//  Created by Christopher Oliver on 12/9/14.
//
//
# pragma once
#ifndef __Olive__ResourceLoader__
#define __Olive__ResourceLoader__

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

#endif /* defined(__Olive__ResourceLoader__) */

class ResourceLoader {
public:
    
    //  -> ResourceLoader*
    // ResourceLoader class constructor that allocates a resource loader object
    // and returns a pointer to it.
    // Example: ResourceLoader* myResourceLoader = ResourceLoader();
    // Strategy: Domain Knowledge
    ResourceLoader();

    // char* -> string
    // Given a pointer to a filename of a text file containing a shader, returns
    // a string containing of the entire contents of the file.
    // INVARIANT: the shader must be in the ./res/shaders/ directory.
    // Example: loadShader(myShaderFileName);
    // Strategy: Domain Knowledge
    std::string loadShader(char* fileName);
    
private:
    
    
};
