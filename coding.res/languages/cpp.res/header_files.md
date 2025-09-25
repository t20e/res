# Header files (.h)

Prerequisite:
- [C++ build process](cpp_build_process.md)

---

Header (.h) files serve as "blueprints" in C++. They contain **declarations** that describe the interface of your code to the compiler.

**What goes in a header file?**

- **Function declarations**: `int multiply(int a, int b);`
- **Class, Structs, and Enum definitions:** The compiler needs to know the full blueprint of a class (e.g., `class Human`) to know it's size and layout.
- **Template definitions:** are a blueprint for generating code.

    ``` C++
    template <typename T>
    T add(T a, T b){
        return a+b;
    }
    ```

- **Inline functions:** The `inline` keyword is an exception to the ODR that allows a function's definition to appear in multiple files.

#### Quick Note On `<>` Angled Brackets Vs "" Double Quotes When Importing

- Use **double quotes** for your own project's header files. The preprocessor will look for the file starting the same directory as the current source file.

    ```C++
    #include "my_file.h"
    ```

- Use **angled brackets** for standard library or system headers. The preprocessor will look for the file in the system's standard include paths, where all default C++ library files are stored.

    ```C++
    #include <iostream>
    ```

### The One Definition Rule (ODR)

The **ODR** rule governs the C++ build process, it states that you can have many **declarations** of something, but you must have **exactly one definition** of it.

- **Declaration:** Tells the compiler "this thing exists" (e.g, a function prototype in a `.h` file).
- **Definition:** Provides the actual code implementation for that thing (e.g., a function's body in a `.cpp` file).

- Note: Including a (.cpp) file into another(.cpp) file would break ODR, that's why we use headers.

### Typical Class Structure In C++

**The header (`Human.h`) - The blueprints:**

- It should contain the entire class definition, so the compiler knows what a `Human` object is.

```C++
#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human {
public:
    std::string name;
    std::string occupation;
    int age;

    // Method DECLARATIONS only
    void eat();
    void drink();
    void sleep();
};

#endif
```

**The source (`Human.cpp`) - The implementation:**

- Note: This file contains the **definitions** of the `human` class's member functions (eat(), drink(), etc..). This will be the **only** place these definitions exist, in the entire program, satisfying ODR!

```C++
#include "Human.h" // Include the blueprint/header
#include <iostream>

// Method DEFINITIONS
void Human::eat() {
    std::cout << this->name << " is eating\n";
}

void Human::drink() {
    std::cout << this->name << " is drinking\n";
}

void Human::sleep() {
    std::cout << this->name << " is sleeping\n";
}
```

**In your `main.cpp`:**

```C++
#include <iostream>
#include "Human.h" // Include the blueprint/header

int main() {
    Human human1;

    human1.name = "Rick";
    human1.occupation = "scientist";
    human1.age = 70;

    std::cout << human1.name << "\n";
    std::cout << human1.age << "\n";
    std::cout << human1.occupation << "\n";

    human1.drink(); // Prints "Rick is drinking"

    return 0;
}
```
