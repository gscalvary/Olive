//
//  Window.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include "Window.h"

Window::Window(unsigned width, unsigned height) {
    
    this->width = width;
    this->height = height;
    
}

void Window::CreateOpenGLWindow() {
    
    window = glfwCreateWindow(width, height, "Olive 3D Game Engine", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
    }
}
