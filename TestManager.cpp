//
//  TestManager.cpp
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//

#include "TestManager.h"

TestManager* TestManager::s_TestManager = NULL;

TestManager::TestManager() {
    
    
}

TestManager& TestManager::getInstance() {
    
    // allocate the TestManager if not already done
    if (s_TestManager == NULL) {
        s_TestManager = new TestManager();
    }
    
    return *s_TestManager;
}

void TestManager::runTests() {
    
    
}