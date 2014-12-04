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
    
    // unsigned, unsigned -> Window*
    // Given width and height integers create a window object and return a
    // pointer to it.
    // INVARIANTS: width and height > 0
    // Example: Window* mainWindow = Window(800, 600);
    // Strategy: Domain Knowledge
    Window(unsigned width, unsigned height);
    
    // EFFECT: Via GLFW create an OpenGL context window using the Window object
    // parameters.
    // Example: mainWindow->CreateWindow();
    // Strategy: Function Composition
    void CreateOpenGLWindow();
    
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
    
    //  -> GLFWwindow*
    // Return the GLFWwindow pointer for this Window.
    // Example: getWindowGLFWPointer();
    // Strategy: Domain Knowledge
    GLFWwindow* getWindowGLFWPointer();
    
private:
    
    unsigned width;
    unsigned height;
    GLFWwindow* window;
    
};
