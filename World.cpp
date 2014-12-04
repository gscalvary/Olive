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

    // create a main window object
    Window* mainWindow = new Window(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
    
    // create an OpenGL context for the main window
    mainWindow->CreateOpenGLWindow();
    // make the main window the current context
    glfwMakeContextCurrent(mainWindow->getGLFWPointer());
    
    return 0;
}