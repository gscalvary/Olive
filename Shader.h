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
#include <map>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Matrix4f.h"
#include "Vector3f.h"

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
    // Strategy: Function Composition
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
    
    // string& -> void
    // Given a pointer to a string containing the name of our uniform, obtain
    // its memory address from OpenGL and add it to a hash table.
    // Example: addUniform(myUniformName);
    // Strategy: Function Composition
    void addUniform(const std::string& uniformName);
    
    // string&, int -> void
    // Given a pointer to a string containing the name of our uniform and an
    // integer representing the new value of our uniform, call OpenGL to set the
    // value of the uniform.
    // Example: setUniformi(myUniformName, 1);
    // Strategy: Function Composition
    void setUniformi(const std::string& uniformName, int newValue);
    
    // string&, float -> void
    // Given a pointer to a string containing the name of our uniform and a
    // float representing the new value of our uniform, call OpenGL to set the
    // value of the uniform.
    // Example: setUniformf(myUniformName, 1.0f);
    // Strategy: Function Composition
    void setUniformf(const std::string& uniformName, float newValue);
    
    // string&, Vector3f* -> void
    // Given a pointer to a string containing the name of our uniform and a
    // pointer to a Vector3f, call OpenGL to set the value of the uniform to the
    // values of the Vector3f.
    // Example: setUniformVector3f(myUniformName, myVector3fPtr);
    // Strategy: Function Composition
    void setUniformVector3f(const std::string& uniformName, Vector3f* ptr);
    
    // string&, Matrix4f* -> void
    // Given a pointer to a string containing the name of our uniform and a
    // pointer to a Matrix4f, call OpenGL to set the value of the uniform to the
    // values of the Matrix4f.
    // Example: setUniformMatrix4f(myUniformName, myMatrix4fPtr);
    // Strategy: Function Composition
    void setUniformMatrix4f(const std::string& uniformName, Matrix4f* ptr);
    
private:
    
    // string&, int -> void
    // Given a pointer to a string containing shader program text and an integer
    // denoting the type of shader compile the shader program.
    // Example: compileFragmentShader(myShaderText, GL_VERTEX_SHADER);
    // Strategy: Function Composition
    void compileShader(const std::string& shaderText, int shaderType);
    
    GLuint program;
    static std::map<std::string, GLuint> uniformMap;
};
