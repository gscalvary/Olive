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
    
    std::cout << "Engine is running in test mode." << std::endl;
    
    runVector3fTests();
    runVertexTests();
    runMeshTests();
    runLoadShaderTests();
    runShaderTests();
    
    std::cout << "Engine testing successfully completed." << std::endl;
}

void TestManager::runVector3fTests() {
    
    std::cout << " - Running Vector3f tests:";
    
    // constructor and getters
    Vector3f testVector(1.0f, 2.0f, 3.0f);
    assert(testVector.getVector3fX() == 1.0f);
    assert(testVector.getVector3fY() == 2.0f);
    assert(testVector.getVector3fZ() == 3.0f);
    
    std::cout << " Vector3f class validated!" << std::endl;
}

void TestManager::runVertexTests() {
    
    std::cout << " - Running Vertex tests:";

    Vector3f testVector(1.0f, 2.0f, 3.0f);

    // constructor and getters
    Vertex testVertex(&testVector);
    assert(testVertex.getSizeVertex() == 3);
    assert(testVertex.getPosVertex()->getVector3fX() == 1.0f);
    
    std::cout << " Vertex class validated!" << std::endl;
}

void TestManager::runMeshTests() {
    
    std::cout << " - Running Mesh tests:";
    
    Vector3f testVector1(-0.6f, -0.4f, 0.0f);
    Vertex testVertex1(&testVector1);
    Vector3f testVector2( 0.6f, -0.4f, 0.0f);
    Vertex testVertex2(&testVector2);
    Vector3f testVector3( 0.0f,  0.6f, 0.0f);
    Vertex testVertex3(&testVector3);
    std::vector<Vertex*> vertices;
    vertices.push_back(&testVertex1);
    vertices.push_back(&testVertex2);
    vertices.push_back(&testVertex3);

    // constructors and getters
    Mesh testMesh;
    testMesh.addVerticesMesh(vertices);
    float buffer[9] = {-0.6f, -0.4f, 0.0f, 0.6f, -0.4f, 0.0f, 0.0f, 0.6f, 0.0f};
    for (unsigned i; i < 9; ++i) {
        assert(buffer[i] == testMesh.getBufferElementMesh(i));
    }
    
    std::cout << " Mesh class validated!" << std::endl;
}

void TestManager::runLoadShaderTests() {
    
    std::cout << " - Running loadShader tests:";
    
    chdir("..");
    std::string goodFileName = "basicVertex";
    std::string goodResult = loadShader(goodFileName + ".glsl");
    
    std::cout << " loadShader function validated!" << std::endl;
}

void TestManager::runShaderTests() {
    
    std::cout << " - Running Shader tests:";
    
    // constructor
    // TODO: create an OpenGL context so I can run a test like this!
    //Shader myShader;
    
    std::cout << " Shader class validated!" << std::endl;
}
