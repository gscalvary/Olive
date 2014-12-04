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
#include <string>

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
    
private:
    
    unsigned width;
    unsigned height;
    GLFWwindow* window;
    
};
