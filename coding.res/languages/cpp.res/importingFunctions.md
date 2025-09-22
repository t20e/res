# Importing External Functions in C++


💡 **Automating Below Process With [Make or CMAKE](CMake_vs_Make.md):**

**Import:**

- The `Header file (.h)`:
  - *The header file or public interface acts like a declaration file, it tells the compiler what functions, classes, or variables **exist** in your program without defining their implementation.*

  - Create a header file containing math util function declarations: `math_utils.h`;
  - In `math_utils.h`:

    ```c++  
    #ifndef MATH_UTILS_H
    #define MATH_UTILS_H

    // Declare the function signature.
    int calculate_area(int length, int width);

    #endif ****
    ```

- The `implementation file (.cpp)`:
  - *This file contains the function definitions, which is the code that implements the functions logic. The file must include its own corresponding header file to ensure that the function's definition matches its declaration.*

  - Eg., `math_utils.cpp` and in it:

    ```c++
    // Include the corresponding header file.
    #include "math_utils.h"

    // define the function
    int calculate_area(int length, int width){
        return length * width;
    }
    ```

- The file importing:
  - *Only need to import the header to access all the functions declared in it.*

    `main.cpp`

    ```c++
        #include <iostream>
        // Include the header file
        #include "math_utils.h"

        int main(){
            // call the external function
            int result = calculate_area(5, 10);
            std::cout << "Area is: " << result << std::endl;
            return 0;
        }
    ```

**Compiling and Linking:**

```shell
clang++ main.cpp math_utils.cpp -o area_calculator
```
