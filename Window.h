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
    
    // unsigned, unsigned, char*, bool, bool, bool -> Window*
    // Given width and height integers, a name string, a boolean representing
    // whether antiAliasing is on or off, a boolean representing whether the
    // window is full screen or not and a boolean representing if the window
    // may be resized create a window object and return a pointer to it.
    // INVARIANTS: width and height > 0
    // Example: Window* mainWindow = Window(800, 600, windowName);
    // Strategy: Domain Knowledge
    Window(unsigned width, unsigned height, char* name);
    
    //  -> GLFWWindow*
    // Via GLFW create an OpenGL context window using the Window object
    // parameters.
    // Example: GLFWwindow* mainWindow = CreateWindow();
    // Strategy: Function Composition
    GLFWwindow* CreateOpenGLWindow();
    
private:
    
    unsigned width;
    unsigned height;
    char* name;
};
