//
//  TestManager.h
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//
# pragma once
#ifndef __Olive__TestManager__
#define __Olive__TestManager__

#include <assert.h>
#include <iostream>
#include <stdio.h>
#include "Input.h"
#include "Mesh.h"
#include "ResourceLoader.h"
#include "Vector3f.h"
#include "Vertex.h"

#endif /* defined(__Olive__TestManager__) */

// singleton shortcut
#define theTest TestManager::getInstance()

class TestManager {
public:
    
    //  -> TestManager*
    // Testmanager class constructor that allocates a test manager object and
    // returns a pointer to it.
    // Example: TestManager* myTestManager = TestManager();
    // Strategy: Domain Knowledge
    TestManager();
    
    //  -> TestManager&
    // Used to access the singleton instance of this class, by using theTest
    // a macro will call this function which returns the address of this object.
    // Example: theTest.someTestManagerMethod
    // Strategy: Domain Knowledge
    static TestManager& getInstance();
    
    //  -> void
    // Run class method tests.
    // Example: theTest.runTests();
    // Strategy: Function Composition
    void runTests();
    
    //  -> void
    // Run Vector3f class method tests.
    // Example: theTest.runVector3fTests();
    // Strategy: Function Composition
    void runVector3fTests();
    
    //  -> void
    // Run Vertex class method tests.
    // Example: theTest.runVertexTests();
    // Strategy: Function Composition
    void runVertexTests();
    
    //  -> void
    // Run Mesh class method tests.
    // Example: theTest.runMeshTests();
    // Strategy: Function Composition
    void runMeshTests();
    
    //  -> void
    // Run ResourceLoader class method tests.
    // Example: theTest.runResourceLoaderTests();
    // Strategy: Function Composition
    void runResourceLoaderTests();
    
    //  -> void
    // Run static function loadShader test.
    // Example: std::string fileName = "badFileName";
    //          std::string result = loadShader(fileName + ".glsl");
    // Strategy: Function Composition
    void runLoadShaderTests();
    
protected:
    
    static TestManager* s_TestManager;
    
private:
    
    
};