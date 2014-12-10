//
//  World.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/3/14.
//
//

#include "World.h"

World* World::s_World = NULL;

World::World() {
    
    mainWindow = NULL;
    gameClock = NULL;
    isWorldRunning = false;
}

World& World::getInstance() {
    
    // allocate the World if not already done
    if (s_World == NULL) {
        s_World = new World();
    }
    
    return *s_World;
}

int World::initializeWorld() {
    
    // set function callback for GLFW errors
    glfwSetErrorCallback(errorCallback);
    
    // initialize the GLFW library
    if (!glfwInit()) {
        return -1;
    }

    // create a main window object
    char myTitle[] = "Olive 3D Game Engine";
    mainWindow = new Window(mainWindowWidth, mainWindowHeight, myTitle);
    
    // create an OpenGL context for the main window
    mainWindow->createOpenGLWindow();
    // make the main window the current context
    glfwMakeContextCurrent(mainWindow->getWindowGLFWPointer());
    // set GLFW to only swap buffers when an update has been made
    glfwSwapInterval(swapInterval);
    
    // set function callback for keyboard input
    glfwSetKeyCallback(mainWindow->getWindowGLFWPointer(), keyboardInput);
    // set function callback for mousebutton input
    glfwSetMouseButtonCallback(mainWindow->getWindowGLFWPointer(),
                               mouseButtonInput);
    // set function callback for mouse motion
    glfwSetCursorPosCallback(mainWindow->getWindowGLFWPointer(), mouseMotion);
    
    // print out OpenGL version
    std::cout << theRender.getOpenGLVersion() << std::endl;
    
    // initialize OpenGL
    theRender.initializeGraphics();
    
    // create a game clock
    gameClock = new Time();
    
    // Set up paths correctly in the .app bundle
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (!CFURLGetFileSystemRepresentation(resourcesURL,
                                          TRUE,
                                          (UInt8 *)path,
                                          PATH_MAX)) {
        std::cout << "ERROR: Problem setting up working directory!";
    }
    CFRelease(resourcesURL);
    chdir(path);
    chdir("..");
    std::cout << getcwd(path, PATH_MAX) << std::endl;
    
    // TODO: REMOVE THIS TEST FUNCTIONALITY!
    Vector3f vector1(0.75f, 0.75f, 0.0f);
    Vector3f vector2(0.75f, -0.75f, 0.0f);
    Vector3f vector3(-0.75f, -0.75f, 0.0f);
    Vertex vertex1(&vector1);
    Vertex vertex2(&vector2);
    Vertex vertex3(&vector3);
    std::vector<Vertex*> vertices = {&vertex1, &vertex2, &vertex3};
    testMesh.addVerticesMesh(vertices);
    
    return 0;
}

int World::runWorld() {
    
    if (isWorldRunning) {
        return 0;
    };
    
    isWorldRunning = true;
    float lastTime = gameClock->getTime();
    float unprocessedTime = 0.0f;
    float frameTime = 1.0/frameCap;
    int frames = 0;
    float frameCounter = 0.0f;
    
    // the game loop
    while (isWorldRunning) {
        
        // limit how often the game loop updates and renders
        bool isTimeToRender = false;
        float startTime = gameClock->getTime();
        float passedTime = startTime - lastTime;
        lastTime = startTime;
        unprocessedTime += passedTime;
        frameCounter += passedTime;
        
        while (unprocessedTime > frameTime) {
            
            isTimeToRender = true;
            unprocessedTime -= frameTime;
            
            // set the delta time in the game clock
            gameClock->setDeltaTime(frameTime);
            
            // process input
            inputForWorld();
            
            // update the world
            updateWorld();
            
            // fps counts
            if (frameCounter >= 1.0) {
                std::cout << frames << std::endl;
                frameCounter = 0.0;
                frames = 0;
            }
        }
        
        // render the world
        if (isTimeToRender) {
            
            ++frames;
            // render
            renderWorld();
        }
        
        // if the mainwindow was closed terminate the run
        if (mainWindow->isWindowCloseRequested()) {
            stopWorld();
        }
    }
    
    return 0;
}

void World::inputForWorld() {
    
    // poll for input events
    glfwPollEvents();
}

void World::renderWorld() {
    
    // clear the screen for the next render
    theRender.clearScreen();
    
    //TODO: REMOVE THIS TEST CODE!
    testMesh.drawMesh();
    
    // swap buffers
    mainWindow->renderWindow();
}

void World::updateWorld() {
    

}

void World::stopWorld() {
    
    if (isWorldRunning) {
        isWorldRunning = false;
    };
}

int World::shutdownWorld() {
    
    // dispose of the main window Open GL Context
    mainWindow->disposeOpenGLWindow();
    // terminate the GLFW library
    glfwTerminate();
    return 0;
}

void World::errorCallback(int error, const char* description) {
    
    std::cout << description << std::endl;
}
