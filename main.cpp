//
//  main.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include <iostream>
#include "World.h"

int main(int argc, const char * argv[]) {
    
    // create a world object
    World* theWorld = new World();
    
    if (!theWorld) {
        std::cout << "The world failed to allocate!" << std::endl;
        return -1;
    }

    // initialize the world
    if (theWorld->initialize() < 0) {
        std::cout << "The world failed to initialize!" << std::endl;
        return -1;
    }
    
    return 0;
}
