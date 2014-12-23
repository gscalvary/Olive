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
    
    if (action == GLFW_REPEAT) {
        if (theInput.onKeyRepeat(key)) {
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

void loadMesh(const std::string& fileName, Mesh* mesh) {
    
    // split the file name by the embedded period
    char sep = '.';
    std::vector<std::string> tokens;
    
    for(size_t p=0, q=0; p!=fileName.npos; p=q) {
        tokens.push_back(fileName.substr(p+(p!=0), (q=fileName.find(sep, p+1))-p-(p!=0)));
    }
    
    // compare the given file type and the type supported
    std::string s = tokens[tokens.size() - 1];
    if (s != "obj") {
        std::cout << "Unable to handle files of type: " << s << std::endl;
        return;
    }
    
    // build variables for mesh loading
    sep = ' ';
    std::vector<Vertex*> vertices;
    std::vector<GLubyte> indices;
    
    // open and read the object file
    std::string line;
    std::string result;
    std::ifstream objFile;
    
    objFile.open(("./res/models/" + fileName).c_str());
    
    if (objFile.is_open()) {
        while(getline(objFile,line)) {
            // operating on one line at a time, tokenize the line by spliting
            // on spaces
            tokens.clear();
            for(size_t p=0, q=0; p!=line.npos; p=q) {
                tokens.push_back(line.substr(p+(p!=0), (q=line.find(sep, p+1))-p-(p!=0)));
            }
            // process vertices
            if (tokens[0] == "v" && tokens.size() == 4) {
                float x = std::stof(tokens[1]);
                float y = std::stof(tokens[2]);
                float z = std::stof(tokens[3]);
                Vector3f* newVector = new Vector3f(x, y, z);
                Vertex* newVertex = new Vertex(newVector);
                delete newVector;
                vertices.push_back(newVertex);
            }
            // process mesh faces
            if (tokens[0] == "f") {
                // faces from Maya are of the form f 54/63/55, the first
                // number corrsponds to the vertex, the others are for textures
                // and normals
                char fSep = '/';
                std::vector<std::string> fTokens;
                for (auto & element: tokens) {
                    if (element != "f") {
                        fTokens.clear();
                        for(size_t p=0, q=0; p!=element.npos; p=q) {
                            fTokens.push_back(element.substr(p+(p!=0), (q=element.find(fSep, p+1))-p-(p!=0)));
                        }
                        // obj files start with vertex 1 while the engine
                        // starts with vertex 0
                        int i = std::stoi(fTokens[0]) - 1;
                        indices.push_back((GLubyte)i);
                    }
                }
            }
        }
        objFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        char path[PATH_MAX];
        std::cout << getcwd(path, PATH_MAX) << std::endl;
    }
    
    // build the mesh
    mesh->addVerticesMesh(vertices, indices);
    
    // clean-up the heap allocated vertices
    for (auto & vertex: vertices) {
        delete vertex;
    }
}
