//
//  World.h
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//
# pragma once
#ifndef __Olive__World__
#define __Olive__World__

#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Window.h"

#endif /* defined(__Olive__World__) */

#define MAIN_WINDOW_WIDTH 800
#define MAIN_WINDOW_HEIGHT 600

class World {
public:
    
    //  -> World*
    // World class constructor that allocates a world object and returns a
    // pointer to it.
    // Example: World* myWorld = World();
    // Strategy: Domain Knowledge
    World();
    
    //  -> int
    // Initialize the game engine:
    //  Initialize GLFW.
    //  Create a main window.
    // Returns 0 if successful or -1 if a failure.
    // Example: myWorld.initialize();
    // Strategy: Function Composition
    int initialize();
    
private:
    
};