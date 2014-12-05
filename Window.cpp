//
//  Window.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include "Window.h"

Window::Window(unsigned width, unsigned height, char* title) {
    
    this->width = width;
    this->height = height;
    this->title = title;
    window = NULL;
}

void Window::createOpenGLWindow() {
    
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if (!window) {
        glfwTerminate();
    }
}

void Window::disposeOpenGLWindow() {
    
    glfwDestroyWindow(window);
}

void Window::renderWindow() {
    
    glfwSwapBuffers(window);
}

bool Window::isWindowCloseRequested() {
    
    return glfwWindowShouldClose(window);
}

unsigned Window::getWindowWidth() {
    
    return width;
}

unsigned Window::getWindowHeight() {
    
    return height;
}

char* Window::getWindowTitle() {
    
    return title;
}

GLFWwindow* Window::getWindowGLFWPointer() {
    
    return window;
}
