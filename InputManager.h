//
//  InputManager.h
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//
# pragma once
#ifndef __Olive__InputManager__
#define __Olive__InputManager__

#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
#include "Vector2f.h"

#endif /* defined(__Olive__InputManager__) */

// singleton shortcut
#define theInput InputManager::getInstance()

class InputManager {
public:

    //  -> InputManager*
    // InputManager class constructor that allocates an InputManager object and
    // returns a pointer to it.
    // Example: InputManager* handleMyInput = InputManager();
    // Strategy: Domain Knowledge
    InputManager();
    
    //  -> InputManager&
    // Used to access the singleton instance of this class, by using theInput
    // a macro will call this function which returns the address of this object.
    // Example: theInput.someInputManagerMethod
    // Strategy: Domain Knowledge
    static InputManager& getInstance();
    
    // int -> bool
    // Process keys that have just been released.
    // Example: onKeyUp(GLFW_KEY_6);
    // Strategy: Function Composition
    bool onKeyUp(int key);
    
    // int -> bool
    // Process keys that have just been pressed.
    // Example: onKeyDown(GLFW_KEY_6);
    // Strategy: Function Composition
    bool onKeyDown(int key);
    
    // int -> bool
    // Process keys that are being held down.
    // Example: onKeyRepeat(GLFW_KEY_6);
    // Strategy: Function Composition
    bool onKeyRepeat(int key);
    
    // int -> bool
    // Process mouse buttons that have just been released.
    // Example: onMouseButtonUp(GLFW_MOUSE_BUTTON_LEFT);
    // Strategy: Function Composition
    bool onMouseButtonUp(int button);
    
    // int -> bool
    // Process mouse buttons that have just been pressed.
    // Example: onMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT);
    // Strategy: Function Composition
    bool onMouseButtonDown(int button);
    
    // double, double -> void
    // Process mouse motion by recording the current mouse position coordinates
    // in vector mousePosition.
    // Example: onMouseMotion(100.0, 200.0) sets mousePosition to
    // (100.0, 200.0);
    // Strategy: Function Composition
    void onMouseMotion(double x, double y);

protected:
    
    static InputManager* s_InputManager;
    
private:
    
    Vector2f mousePosition;
};