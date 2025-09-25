#include "gtest/gtest.h"    // include gtest
#include "math_functions.h" // its header file

// Test suit for multiply function
TEST(MultiplyTest, HandleNegativeInput)
{
    EXPECT_EQ(multiply(10, -1), -10);
}

// Another test with the same `MultiplyTest` suite.
TEST(MultiplyTest, HandlePositiveInput)
{
    EXPECT_EQ(multiply(2, 3), 6);
}

TEST(DivideTest, HandleDivideByZero)
{
    // Expect the function to throw an error when that function has an argument that is 0.
    EXPECT_THROW(divide(10, 0), std::invalid_argument);
}

// --- EXPECT VS ASSERT ---
TEST(confirmNumTest, AssertNumbers)
{
    // THE ARGUMENT MUST BE EQUAL TO 5

    // --- EXPECT_EQ()  ---
    // EXPECT_EQ() if an error occurs the code after it will still run!
    EXPECT_EQ(confirmNum(5), true);
    // EXPECT_EQ(confirmNum(123), true); // ERROR
    // because this error is on an EXPECT_EQ assertion, the code below will still still run, but only for the code in this function block!
    // EXPECT_EQ(confirmNum(6), false);
    // EXPECT_EQ(confirmNum(123), true);
    // EXPECT_EQ(confirmNum(5), true);

    
    // --- ASSERT_EQ ---
    // ASSERT_EQ if an error occurs, no more tests are ran for this function!
    // ASSERT_EQ(confirmNum(5), true);
    // ASSERT_EQ(confirmNum(123), true); // ERROR
    // because this error is on an ASSERT_EQ assertion, Code below does not run, , but only for the code in this function block!
    // ASSERT_EQ(confirmNum(6), false);

    // // This error line is never reached, so we wont get this error!
    // ASSERT_EQ(confirmNum(123), true);
    // ASSERT_EQ(confirmNum(5), true);
}


// --- TEST_F | Test Fixture---
class MyFixture : public ::testing::Test
{
protected:
    std::vector<int> my_vector;

    // This runs before each TEST_F this suit
    void SetUp() override
    {
        my_vector.push_back(1);
        my_vector.push_back(2);
        // Teardown logic can go in TearDown()
    }
};

// The Test Case using the fixture
TEST_F(MyFixture, VectorIsNotEmpty)
{
    EXPECT_FALSE(my_vector.empty());
}

TEST_F(MyFixture, VectorHasTwoElements)
{
    EXPECT_EQ(my_vector.size(), 2);
}


// --- TEST_P | Parameterized Tests ---
// Allows us to run the same test logic with many different input values. Useful when testing a function against a range of data without writing repetitive code.
// It requires:
    // 1. A fixture class that inherits from ::testing::TestWithParam<YourType>
    // 2. A TEST_P case that uses GetParam() to access the current parameter.
    // 3. An INSTANTIATE_TEST_SUITE_P macro to define the set of parameters to test with.

// 1. The fixture
class IsEvenTest: public ::testing::TestWithParam<int>{};

// 2. The test cast
TEST_P(IsEvenTest, HandleMultipleValues){
    int number = GetParam(); // Get the current parameter
    bool result = is_even(number);
    EXPECT_TRUE(result);
}

// 3. The Instantiation
INSTANTIATE_TEST_SUITE_P(
    EvenNumbers,
    IsEvenTest,
    ::testing::Values(0, 2, 4, -8, 100)
); 

