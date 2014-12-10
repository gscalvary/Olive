//
//  Input.h
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//
# pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "InputManager.h"

// GLFW is handling user input for the engine.  GLFW is C based, the callback
// functions for input must not be class methods.

// GLFWwindow*, int, int, int, int -> void
// GIVEN a pointer to a GLFW OpenGL context window, a integer representing a
// keyboard key that was pressed, an integer representing the system scancode
// of the keyboard key that was pressed, an integer representing some action,
// and an integer representing a modifier key that may have been pressed direct
// the input to the InputManager.
// INVARIANTS:  key is defined here:
//  http://www.glfw.org/docs/latest/group__keys.html
//              action is either press, release or repeat
// Example: Called by GLFW, should not be called in engine code directly!
// Strategy: Function Composition
void keyboardInput(GLFWwindow* window, int key, int scancode, int action,
                   int mods);

// GLFWwindow*, int, int, int -> void
// GIVEN a pointer to a GLFW OpenGL context window, a integer representing a
// mouse button that was pressed, an integer representing some action, and an
// integer representing a modifier key that may have been pressed direct
// the input to the InputManager.
// INVARIANTS:  button is defined here:
//  http://www.glfw.org/docs/latest/group__buttons.html
//              action is either press or release
// Example: Called by GLFW, should not be called in engine code directly!
// Strategy: Function Composition
void mouseButtonInput(GLFWwindow* window, int button, int action, int mods);

// GLFWwindow*, double, double -> void
// GIVEN a pointer to a GLFW OpenGL context window, a double representing the
// mouse x coordinate and a double representing the mouse y coordinate direct
// the input to the InputManager.
// Example: Called by GLFW, should not be called in engine code directly!
// Strategy: Function Composition
void mouseMotion(GLFWwindow* window, double x, double y);

// string& -> string
// Given a pointer to a filename of a text file containing a shader, returns
// a string containing of the entire contents of the file.
// INVARIANT: the shader must be in the ./res/shaders/ directory.
// Example: loadShader(myShaderFileName);
// Strategy: Domain Knowledge
static std::string loadShader(const std::string& fileName);
