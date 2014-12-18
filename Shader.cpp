//
//  Shader.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/10/14.
//
//

#include "Shader.h"

// initialize the uniform hash table
std::map<std::string, GLuint> Shader::uniformMap;

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

void Shader::addUniform(const std::string& uniformName) {
    
    // obtain the memory address of the uniform in our shader program object
    GLuint uniformLocation = glGetUniformLocation(program, uniformName.c_str());
    
    // check for errors
    if (uniformLocation == -1) {
        std::cout << "Shader glGetUniformLocation failed for " << uniformName << "!" << std::endl;
    }
    
    // capture the uniform name and location in a hash table for future use
    uniformMap.insert(std::pair<std::string, GLuint>(uniformName,
                                                     uniformLocation));
}

void Shader::setUniformi(const std::string& uniformName, int newValue) {
    
    glUniform1i(uniformMap.at(uniformName), newValue);
}

void Shader::setUniformf(const std::string& uniformName, float newValue) {
    
    glUniform1f(uniformMap.at(uniformName), newValue);
}

void Shader::setUniformVector3f(const std::string& uniformName, Vector3f* ptr) {
    
    glUniform3f(uniformMap.at(uniformName),
                ptr->getVector3fX(),
                ptr->getVector3fY(),
                ptr->getVector3fZ());
}

void Shader::setUniformMatrix4f(const std::string& uniformName, Matrix4f* ptr) {
    
    glUniformMatrix4fv(uniformMap.at(uniformName),
                       1,
                       GL_TRUE,
                       &(ptr->m[0][0]));
}
