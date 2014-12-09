//
//  TestManager.h
//  Olive
//
//  Created by Christopher Oliver on 12/8/14.
//
//

#ifndef __Olive__TestManager__
#define __Olive__TestManager__

#include <stdio.h>

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
    // Function Composition
    void runTests();
    
protected:
    
    static TestManager* s_TestManager;
    
private:
    
    
};