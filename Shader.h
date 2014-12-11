//
//  Shader.h
//  Olive
//
//  Created by Christopher Oliver on 12/10/14.
//
//
# pragma once
#ifndef __Olive__Shader__
#define __Olive__Shader__

#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>

#endif /* defined(__Olive__Shader__) */

class Shader {
public:
    
    //  -> void
    // Constructor for the shader object.
    // Example: Shader myShader;
    // Strategy: Function Composition
    Shader();
    
    // string& -> void
    // Given a pointer to a string containing vertex shader program text compile
    // the shader program.
    // Example: addVertexShader(myShaderText);
    // Strategy: Domain Knowledge
    void addVertexShader(const std::string& shaderText);
    
    // string& -> void
    // Given a pointer to a string containing fragment shader program text
    // compile the shader program.
    // Example: addFragmentShader(myShaderText);
    // Strategy: Domain Knowledge
    void addFragmentShader(const std::string& shaderText);
    
    //  -> void
    // Link a shader program using OpenGL.
    // Example: linkShader();
    // Strategy: Function Composition
    void linkShader();
    
    //  -> void
    // Bind a shader program using OpenGL.
    // Example: bindShader();
    // Strategy: Function Composition
    void bindShader();
    
private:
    
    // string&, int -> void
    // Given a pointer to a string containing shader program text and an integer
    // denoting the type of shader compile the shader program.
    // Example: compileFragmentShader(myShaderText, GL_VERTEX_SHADER);
    // Strategy: Function Composition
    void compileShader(const std::string& shaderText, int shaderType);
    
    GLuint program;
};
