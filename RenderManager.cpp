//
//  RenderManager.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/7/14.
//
//

#include "RenderManager.h"

RenderManager* RenderManager::s_RenderManager = NULL;

RenderManager::RenderManager() {
    
    
}

RenderManager& RenderManager::getInstance() {
    
    // allocate the RenderManager if not already done
    if (s_RenderManager == NULL) {
        s_RenderManager = new RenderManager();
    }
    
    return *s_RenderManager;
}

void RenderManager::clearScreen() {
    
    // TODO: Stencil buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderManager::initializeGraphics() {
    
    // specifies the clear values (R, G, B, A) for the color buffer.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // specifies clock-wise winded polygons to be front facing.
    glFrontFace(GL_CW);
    // specifies back facing polygons to be culled.
    glCullFace(GL_BACK);
    // specifies that lower-depth pixels should not be processed if higher-depth
    // pixels exist.
    glEnable(GL_DEPTH_TEST);
    // TODO: GL DEPTH CLAMP and OpenGL 3.0
    // This is an OpenGL 3.0 feature for gamma correction which I may not yet
    // have the software for on my Mac yet.
    //glEnable(GL_FRAMEBUFFER_SRGB);
}