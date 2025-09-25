#ifndef MOCK_HUMAN_H
#define MOCK_HUMAN_H


// Using GMOCK, we create a mock version of our interface. The MOCK_METHOD macro automatically generates the mock implementation for us.

#include "IHuman.h"
#include "gmock/gmock.h" // Include the GMock header

class MockHuman : public IHuman {
public:
    // MOCK_METHOD(ReturnType, MethodName, (Arguments...));
    MOCK_METHOD(void, Eat, (), (override));
    MOCK_METHOD(void, Sleep, (), (override));
};

#endif