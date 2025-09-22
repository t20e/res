# Importing External Functions in C++

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

    #endif // MATH_UTILS_H
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

---

💡 **Automating This Process With A Makefile:**

- A **Makefile** is a script that automates the build process, so if we have **many** external functions and dependencies, instead of linking each when compiling we can automate the process with `make`:
  - Note: we still need header files files.

`Makefile`

```c
CXX = clang++
CXXFLAGS = -std=c++17 -Wall
TARGET = area_calculator # compiled program name
OBJS = main.o math_utils.o

# $@: The name of the target.
# $^: The names of all the prerequisites (e.g., main.o math_utils.o)
# $<: The name of the first prerequisite (e.g., main.cpp)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

math_utils.o: math_utils.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
```

**Build:**

```shell
cd to_project_folder
# build
make
```

- Note: run `make clean` if you want to delete the compiled program
