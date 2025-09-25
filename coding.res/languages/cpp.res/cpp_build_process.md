# The C++ Build Process

Building a C++ executable file involves three main stages: **preprocessing**, **compilation**, and **linking**.

1. Preprocessing:

   - The preprocessor is an assistant that prepares your code for the compiler. The assistant goes through all (.cpp) files and handles any line that starts with a `#`, like the `#include` directive. when it sees that line, it literally replaces that line with the entire text content of the specified header file.

2. Compilation:
   - Then, the compiler like (`g++` or `clang++`) takes over. Its job is to convert a single preprocessed source file called a `translation unit` into a machine-code "object" (.o) or (.obj) file.
     - A `translation unit` is a single (.cpp) file plus all the content of its included header files that were pasted into it by the preprocessor.
     - The compiler performs each conversion in complete isolation, without knowing that other (.cpp) files exist. This process is called **separate compilation**.
3. Linking
   - Finally, the linker takes all the separate object (.o) files created by the compiler and connects them. If one object file uses a function that is defined in another object file, the linker resolves this reference and combines them into a `single executable file`.

Example:

- In a (.h) file called (math_functions.h):

    ```C++
    #ifndef MATH_FUNCTIONS_H
    #define MATH_FUNCTIONS_H

    int multiply(int a, int b); // declare the function

    #endif
    ```

- In a (.cpp) file called (math_functions.cpp):

    ```C++
    #include "iostream"
    #include "math_functions.h"

    int multiply(int a, int b) // the functions definition
    {
        return a * b;
    }
    ```

- In the main (.cpp) file:

    ```C++
    #include "math_functions.h" 
    // The `#include` directive above tells the PREPROCESSOR to replace that line with all DECLARATION code from (math_functions.h) into this main file (RIGHT HERE)! However, do note that it NEVER includes the source file that has the definitions related to that header file.

    // Then when the LINKER sees that the completed main.cpp object (.o) file is asking for the definitions of multiply(); it links the (.o) file that has the definition of multiply() to create a final executable file.

    int main(){
        multiply(5, 3);
        return 0;
    }
    ```
