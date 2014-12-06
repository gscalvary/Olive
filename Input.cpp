//
//  Input.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//

#include "Input.h"

void keyboardInput(GLFWwindow* window, int key, int scancode, int action,
                   int mods) {
    
    if (action == GLFW_PRESS) {
        if (theInput.onKeyDown(key)) {
            return;
        }
    }
    
    if (action == GLFW_RELEASE) {
        if (theInput.onKeyUp(key)) {
            return;
        }
    }
}

void mouseButtonInput(GLFWwindow* window, int button, int action, int mods) {
 
    if (action == GLFW_PRESS) {
        if (theInput.onMouseButtonDown(button)) {
            return;
        }
    }
    
    if (action == GLFW_RELEASE) {
        if (theInput.onMouseButtonUp(button)) {
            return;
        }
    }
}

void mouseMotion(GLFWwindow* window, double x, double y) {
    
    theInput.onMouseMotion(x, y);
}