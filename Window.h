//
//  Window.h
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//
# pragma once
#ifndef __Olive__Window__
#define __Olive__Window__

#include <stdio.h>
#include <GLFW/glfw3.h>

#endif /* defined(__Olive__Window__) */

class Window {
public:
    
    // unsigned, unsigned, char* -> Window*
    // Given width and height integers and a title create a window object and
    // return a pointer to it.
    // INVARIANTS: width and height > 0
    // Example: Window* mainWindow = Window(800, 600, "My Window");
    // Strategy: Domain Knowledge
    Window(unsigned width, unsigned height, char* title);
    
    // EFFECT: Via GLFW create an OpenGL context window using the Window object
    // parameters.
    // Example: mainWindow->CreateWindow();
    // Strategy: Function Composition
    void createOpenGLWindow();
    
    // EFFECT: Via GLFW dispose of the OpenGL contect window created.
    // Example: mainWindow->disposeWindow();
    // Strategy: Function Composition
    void disposeOpenGLWindow();
    
    // EFFECT: Render to the window by swapping GLFW buffers.
    // Example: mainWindow->renderWindow();
    // Strategy: Function Composition
    void renderWindow();

    //  -> bool
    // Return whether or not the window has been flagged for closing.
    // Example: isWindowCloseRequested();
    // Strategy: Function Composition
    bool isWindowCloseRequested();
    
    //  -> unsigned
    // Return the width of the window.
    // INVARIANT: width > 0
    // Example: getWindowWidth();
    // Strategy: Domain Knowledge
    unsigned getWindowWidth();
    
    //  -> unsigned
    // Return the height of the window.
    // INVARIANT: height > 0
    // Example: getWindowHeight();
    // Strategy: Domain Knowledge
    unsigned getWindowHeight();
    
    //  -> char*
    // Return the a pointer to the title of the window.
    // Example: getWindowTitle();
    // Strategy: Domain Knowledge
    char* getWindowTitle();
    
    //  -> GLFWwindow*
    // Return the GLFWwindow pointer for this Window.
    // Example: getWindowGLFWPointer();
    // Strategy: Domain Knowledge
    GLFWwindow* getWindowGLFWPointer();
    
private:
    
    unsigned width;
    unsigned height;
    char* title;
    GLFWwindow* window;
    
};
