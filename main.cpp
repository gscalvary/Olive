//
//  main.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include <iostream>
#include "TestManager.h"
#include "World.h"

int main(int argc, const char * argv[]) {

    // check program options
    for (int i = 1; i < argc; ++i) {
        // the -t option runs engine tests and returns
        if (strcmp(argv[i], "-t") == 0) {
            theTest.runTests();
            return 0;
        }
    }
        
    // initialize the world
    if (theWorld.initializeWorld() < 0) {
        std::cout << "The world failed to initialize!" << std::endl;
        return -1;
    }
    
    // run the world
    if (theWorld.runWorld() < 0) {
        std::cout << "The world has stopped running!" << std::endl;
        return -1;
    }

    // clean-up the world
    if (theWorld.shutdownWorld() < 0) {
        std::cout << "The world failed to shut-down!" << std::endl;
        return -1;
    }
    
    return 0;
}
