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

Mesh* loadMesh(const std::string& fileName) {
    
    // split the file name by the embedded period
    char sep = '.';
    std::vector<std::string> nameParts;
    
    for(size_t p=0, q=0; p!=fileName.npos; p=q) {
        nameParts.push_back(fileName.substr(p+(p!=0), (q=fileName.find(sep, p+1))-p-(p!=0)));
    }
    
    // compare the given file type and the typ supported
    std::string s = nameParts[nameParts.size() - 1];
    if (s != "obj") {
        std::cout << "Unable to handle files of type: " << s << std::endl;
        return NULL;
    }
    
    std::vector<Vertex*> vertices;
    std::vector<GLubyte> indices;
    
    std::string line;
    std::string result;
    std::ifstream objFile;
    
    objFile.open(("./res/models/" + fileName).c_str());
    
    if (objFile.is_open()) {
        while(getline(objFile,line)) {
            result.append(line + "\n");
        }
        objFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        char path[PATH_MAX];
        std::cout << getcwd(path, PATH_MAX) << std::endl;
    }
    
    return NULL;
}
