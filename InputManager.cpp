//
//  InputManager.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/6/14.
//
//

#include "InputManager.h"

InputManager* InputManager::s_InputManager = NULL;

InputManager::InputManager() {
    

}

InputManager& InputManager::getInstance() {
    
    // allocate the InputManager if not already done
    if (s_InputManager == NULL) {
        s_InputManager = new InputManager();
    }
    
    return *s_InputManager;
}

bool InputManager::onKeyUp(int key) {
    
    if (key == GLFW_KEY_UP) {
        std::cout << "We've just released up!" << std::endl;
    }
    
    return true;
}


bool InputManager::onKeyDown(int key) {

    if (key == GLFW_KEY_UP) {
        std::cout << "We've just pressed up!" << std::endl;
    }
    
    return true;
}

bool InputManager::onMouseButtonUp(int button) {
    
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        std::cout << "We've just released left mouse button!" << std::endl;
    }
    
    return true;
}

bool InputManager::onMouseButtonDown(int button) {
    
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        std::cout << "We've just pressed left mouse button at coordinates: "
        << mousePosition.reportVector2f() << "!" << std::endl;
    }
    
    return true;
}

void InputManager::onMouseMotion(double x, double y) {
    
    mousePosition.setVector2fX((float)x);
    mousePosition.setVector2fY((float)y);
}
