//
//  RenderManager.h
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//
# pragma once
#ifndef __Olive__RenderManager__
#define __Olive__RenderManager__

#include <stdio.h>
#include <GLFW/glfw3.h>

#endif /* defined(__Olive__RenderManager__) */

// singleton shortcut
#define theRender RenderManager::getInstance()

class RenderManager {
public:
    
    //  -> RenderManager*
    // RenderManager class constructor that allocates a RenderManager object and
    // returns a pointer to it.
    // Example: RenderManager* myRenderManager = RenderManager();
    // Strategy: Domain Knowledge
    RenderManager();
    
    //  -> RenderManager&
    // Used to access the singleton instance of this class, by using theRender
    // a macro will call this function which returns the address of this object.
    // Example: theRender.someRenderManagerMethod
    // Strategy: Domain Knowledge
    static RenderManager& getInstance();
    
    //  -> void
    // Clear the screen via a call to OpenGL.
    // Example: theRender->clearScreen()
    // Strategy: Function Composition
    void clearScreen();
    
    //  -> void
    // Initialize graphics via a call to OpenGL.
    // Example: theRender->initializeGraphics()
    // Strategy: Function Composition
    void initializeGraphics();
    
protected:
    
    static RenderManager* s_RenderManager;
    
private:
    
    
};