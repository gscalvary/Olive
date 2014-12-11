//
//  Shader.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/10/14.
//
//

#include "Shader.h"

Shader::Shader() {
    
    program = glCreateProgram();
    
    if (program == 0) {
        std::cout << "Shader glCreateProgram failed!" << std::endl;
    }
}

void Shader::addVertexShader(const std::string& shaderText) {
    
    compileShader(shaderText, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(const std::string& shaderText) {
    
    compileShader(shaderText, GL_FRAGMENT_SHADER);
}

void Shader::compileShader(const std::string& shaderText, int shaderType) {
    
    // create a shader program object
    GLuint shaderProgram = glCreateShader(shaderType);
    // check for errors
    if (shaderProgram == 0) {
        std::cout << "Shader glCreateShader failed!" << std::endl;
    }
    
    // compile the program
    const GLchar* shaderTextPtr[1];
    shaderTextPtr[0] = shaderText.c_str();
    GLint pgmLength[1];
    pgmLength[0] = (GLint)shaderText.length();
    
    glShaderSource(shaderProgram, 1, shaderTextPtr, pgmLength);
    glCompileShader(shaderProgram);
    
    // check for errors
    GLint params;
    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &params);
    if (!params) {
        GLchar infoLog[1024];
        glGetShaderInfoLog(shaderProgram, 1024, NULL, infoLog);
        std::cout << "Shader glCompileShader failed!\n" << infoLog << std::endl;
    }
    
    // attach the shader program to the program
    glAttachShader(program, shaderProgram);
}

void Shader::linkShader() {
    
    // link the program
    glLinkProgram(program);
    
    // check for errors
    GLint params;
    glGetProgramiv(program, GL_LINK_STATUS, &params);
    if (!params) {
        GLchar infoLog[1024];
        glGetProgramInfoLog(program, 1024, NULL, infoLog);
        std::cout << "Shader glLinkProgram failed!\n" << infoLog << std::endl;
    }
    
    // finally, validate the program
    glValidateProgram(program);
    
    // check for errors
    glGetProgramiv(program, GL_VALIDATE_STATUS, &params);
    if (!params) {
        GLchar infoLog[1024];
        glGetProgramInfoLog(program, 1024, NULL, infoLog);
        std::cout << "Shader glValidateProgram failed!\n" << infoLog << std::endl;
    }
}

void Shader::bindShader() {
    
    glUseProgram(program);
}
