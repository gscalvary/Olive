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

std::string loadShader(const std::string& fileName) {
    
    std::string line;
    std::string result;
    std::ifstream shaderFile;
    
    shaderFile.open(("./res/shaders/" + fileName).c_str());
    
    if (shaderFile.is_open()) {
        while(getline(shaderFile,line)) {
            result.append(line + "\n");
        }
        shaderFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        char path[PATH_MAX];
        std::cout << getcwd(path, PATH_MAX) << std::endl;
    }
    
    return result;
}
