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

#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Time.h"
#include "Window.h"

#endif /* defined(__Olive__World__) */

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
    //  - Initialize GLFW.
    //  - Create a main window.
    // Returns 0 if successful or -1 if a failure.
    // Example: myWorld->initializeWorld();
    // Strategy: Function Composition
    int initializeWorld();
    
    //  -> int
    // Run the game world returning 0 upon a successful run and a negative
    // return code otherwise.
    // Example: myWorld->runWorld();
    // Strategy: Function Composition
    int runWorld();
    
    //  -> int
    // Shut-down the game world returning 0 upon a successful run and a negative
    // return code otherwise.
    //  - Terminate GLFW.
    // Example: myWorld->shutdownWorld();
    // Strategy: Function Composition
    int shutdownWorld();
    
private:

    //  -> void
    // Handle input to the world.
    // Example: inputForWorld();
    // Strategy: Function Composition
    void inputForWorld();
    
    //  -> void
    // Render the game world.
    // Example: renderWorld();
    // Strategy: Function Composition
    void renderWorld();
    
    //  -> void
    // Stop the game world.
    // Example: myWorld->stopWorld();
    // Strategy: Domain Knowledge
    void stopWorld();
    
    //  -> void
    // Update the world.
    // Example: updateWorld();
    // Strategy: Function Composition
    void updateWorld();
    
    Window* mainWindow;
    Time* gameClock;
    bool isWorldRunning;
    const unsigned mainWindowWidth = 800;
    const unsigned mainWindowHeight = 600;
    const unsigned swapInterval = 1;
    const float frameCap = 100.0;
};