//
//  World.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include "World.h"

World::World() {
    
    mainWindow = NULL;
    isWorldRunning = false;
}

int World::initializeWorld() {
    
    // initialize the GLFW library
    if (!glfwInit()) {
        return -1;
    }

    // create a main window object
    char myTitle[] = "Olive 3D Game Engine";
    mainWindow = new Window(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, myTitle);
    
    // create an OpenGL context for the main window
    mainWindow->createOpenGLWindow();
    // make the main window the current context
    glfwMakeContextCurrent(mainWindow->getWindowGLFWPointer());
    // set GLFW to only swap buffers when an update has been made
    glfwSwapInterval(GLFW_SWAP_INTERVAL);
    
    return 0;
}

int World::runWorld() {
    
    if (isWorldRunning) {
        return 0;
    };
    
    isWorldRunning = true;
    
    // the game loop
    while (isWorldRunning) {
        // if the mainwindow was closed terminate the run
        if (mainWindow->isWindowCloseRequested()) {
            stopWorld();
        }
        // render the world
        renderWorld();
        // poll for input events
        glfwPollEvents();
    }
    
    return 0;
}

void World::renderWorld() {
    
    mainWindow->renderWindow();
}


void World::stopWorld() {
    
    if (isWorldRunning) {
        isWorldRunning = false;
    };
}

int World::shutdownWorld() {
    
    // dispose of the main window Open GL Context
    mainWindow->disposeOpenGLWindow();
    // termintate the GLFW library
    glfwTerminate();
    return 0;
}
