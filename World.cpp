//
//  World.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include "World.h"

World::World() {
    
    
}

int World::initialize() {
    
    // initialize the GLFW library
    if (!glfwInit()) {
        return -1;
    }
    
    Window* mainWindow = new Window(MAIN_WINDOW_WIDTH,
                                    MAIN_WINDOW_HEIGHT,
                                    'Olive 3D Game Engine');
    
    return 0;
}