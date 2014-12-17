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

#import <CoreFoundation/CoreFoundation.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include "Input.h"
#include "InputManager.h"
#include "Mesh.h"
#include "Shader.h"
#include "RenderManager.h"
#include "Time.h"
#include "Window.h"

//TODO: remove this test code
#include <cmath>

#endif /* defined(__Olive__World__) */

// singleton shortcut
#define theWorld World::getInstance()

class World {
public:
    
    //  -> World*
    // World class constructor that allocates a world object and returns a
    // pointer to it.
    // Example: World* myWorld = World();
    // Strategy: Domain Knowledge
    World();
    
    //  -> World&
    // Used to access the singleton instance of this class, by using theWorld
    // a macro will call this function which returns the address of this object.
    // Example: theWorld.someWorldMethod
    // Strategy: Domain Knowledge
    static World& getInstance();
    
    //  -> int
    // Initialize the game engine:
    //  - Initialize GLFW.
    //  - Initialize OpenGL.
    //  - Create a main window.
    //  - Create a game clock.
    //  - Set-up the application directory.
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

    // int, const char* -> void
    // A method to accept errors from GLFW if they should occur.
    // Example: should not be called by the application, GLFW will call this
    // method directly.
    // Strategy: Function Composition
    static void errorCallback(int error, const char* description);
    
protected:
    
    static World* s_World;

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
    
    // TODO: delete this test code!
    Mesh testMesh;
    Shader* testShader;
    float testUniform;
};