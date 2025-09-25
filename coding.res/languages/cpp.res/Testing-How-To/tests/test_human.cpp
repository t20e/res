#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockHuman.h"   // Our mock class
#include "WorkManager.h" // The class we are testing

// Use a "testing" namespace to keep things clean
using namespace testing;

TEST(WorkManagerTest, ManagesDayCorrectly) {
    // 1. Create the mock object
    MockHuman mock_human;

    // 2. Set Expectations: We expect Eat() and Sleep() to be called exactly once.
    // The order doesn't matter unless specified.
    EXPECT_CALL(mock_human, Eat()).Times(1);
    EXPECT_CALL(mock_human, Sleep()).Times(1);

    // 3. Inject the mock and run the code under test
    WorkManager manager(mock_human);
    manager.manageDay();

    // 4. GMock automatically verifies the expectations were met when mock_human goes out of scope.
}