//
//  Window.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include "Window.h"

Window::Window(unsigned width, unsigned height, char* name) {
    
    this->width = width;
    this->height = height;
    this->name = name;
    
}

GLFWwindow* Window::CreateOpenGLWindow() {
    
    GLFWwindow* window;
    
    window = glfwCreateWindow(width, height, name, NULL, NULL);
    
    if (!window) {
        glfwTerminate();
    }
    
    // make the window's context current
    glfwMakeContextCurrent(window);
    
    return window;
}
