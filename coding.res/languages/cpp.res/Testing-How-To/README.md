# C++ Testing

**Prerequisite:**

- [Google test (GTest)](https://github.com/google/googletest/tree/main#)

    ```shell
    # From the root of the project
    git clone https://github.com/google/googletest.git
    ```

  - GTest is extremely popular and widely used testing framework for C++ projects.

*Folder structure:*

    root
    ├── build
    ├── googletest
    ├── include
    │   └── math_functions.h
    ├── src
    │   └── math_functions.cpp
    ├── tests
    │   └── test_math.cpp
    ├── Makefile
    └── README.md

## Google Test

**See:**
- [math_functions.cpp](src/math_functions.cpp)
- [math_functions.h](include/math_functions.h)
- [test_math.cpp](tests/test_math.cpp)
- [makefile](makefile)

### Compiling and Running Tests:

Using the `Makefile` to compile and run the tests.

```shell
# Compile and run test executables
make test # the test rule from the Makefile
```


### Assertions:

- When using GoogleTest, you start by writing assertions, which are statements that check whether a condition is true. An assertion’s result can be success, nonfatal failure, or fatal failure.

- `EXPECT_*` is a **non-fatal** failure. It reports the error but allows the test function to continue running. Use to find as many errors as possible.
- `ASSERT_*` is a **fatal** failure. It reports the error and **aborts** the current test function immediately. Use when it would be pointless to continue running the code after it.
  
- There are other assertion macros...

  - `TEST_F()`: The test fixture. Use when you have a group of test functions that all need the same setup and teardown, e.g,. same arguments. This keeps the code DRY.

  - **Other common Assertions:**

    | Assertion             | Checks                                     |
    | --------------------- | ------------------------------------------ |
    | `EXPECT_TRUE(cond);`  | `cond` is true                             |
    | `EXPECT_EQ(a, b);`    | `a == b`                                   |
    | `EXPECT_NE(a, b);`    | `a != b`                                   |
    | `EXPECT_GT(a, b);`    | `a > b`                                    |
    | `EXPECT_THROW(op,ex);`| The operation `op` throws exception `ex`   |
    | ..And a lot more... | ...   |


### Typical Test Function:

```C++
TEST(TestSuiteName, TestName) {
    // EXPECT_EQ( function_name( function_parameters ), the expected result);
    EXPECT_EQ(multiply(10, -1), -1);
}
```

- Both `TestSuiteName`, `TestName` must be valid C++ identifiers.

### Mocking

- [test_human.cpp](tests/test_human.cpp)
- [WorkManager.cpp](src/WorkManager.cpp)
- [DatabaseHuman.cpp](src/DatabaseHuman.cpp)


- [MockHuman.h](include/MockHuman.h)
- [DatabaseHuman.h](include/DatabaseHuman.h)
- [IHuman.h](include/IHuman.h)
- [WorkManager.h](include/WorkManager.h)

For cases where your program has dependencies such as databases, makes network calls, API calls, or interacts with other complex classes. mocking allows us to replace these real dependencies with "fake" or mock objects.


