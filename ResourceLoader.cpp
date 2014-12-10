//
//  ResourceLoader.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/9/14.
//
//

#include "ResourceLoader.h"

ResourceLoader::ResourceLoader() {
    
    
}

std::string loadShader(char* fileName) {
    
    std::string line;
    std::ostringstream ostr;
    char directory[80] = "./res/shaders/";
    std::ifstream shaderFile (strcat(directory, fileName));
    
    if (shaderFile.is_open()) {
        while(getline(shaderFile,line)) {
            ostr << line << "\n";
        }
        shaderFile.close();
    } else {
        std::cout << "Unable to open file";
    }
    
    std::string s = ostr.str();
    
    return s;
}