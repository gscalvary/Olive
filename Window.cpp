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
    window = NULL;
}

void Window::CreateOpenGLWindow() {
    
    window = glfwCreateWindow(width, height, "Olive 3D Game Engine", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
    }
}

unsigned Window::getWindowWidth() {
    
    return width;
}

unsigned Window::getWindowHeight() {
    
    return height;
}

GLFWwindow* Window::getWindowGLFWPointer() {
    
    return window;
}
