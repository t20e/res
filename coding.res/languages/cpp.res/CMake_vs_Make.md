# Build Automation Tool CMake vs Make

**Note**: Built on the .cpp and .h files from [importingFunctions.md](importingFunctions.md)

## Make

⭐️ [A more sophisticated makefile](https://github.com/t20e/encryptor/blob/main/Makefile) | ⭐️ [Another](https://github.com/t20e/Http_Server_cpp/blob/main/Makefile)

For testing see [GTest Makefile](Testing-How-To/Makefile).

---

-   Make is a build automation tool that executes commands defined in a `Makefile` to compile and link source files. So if we have a large project with many files, instead of linking them one by one in the CLI we can automate that process with one Makefile and run it with just one command `make` .

**Makefile Example:**

```Make
# Assign variable `CXX` to the clang++ compiler
CXX = clang++

# Assign CXXFLAGS variable that defines compiler flags
# -Wall enable all compiler warnings
# The `-MMD` and `-MP` flags generate dependency files (.d) that track header file changes.
# If you modify a header file, 'make' will know to recompile the source files that include that header file.
CXXFLAGS = -std=c++17 -Wall -MMD -MP

# The name of the final executable file
TARGET = area_calculator

# A list of all C++ source (.cpp) files
SRCS = main.cpp math_utils.cpp

# Automatically generate a list of object (.o) files from the source files
OBJS = $(SRCS:.cpp=.o)

# --- Makefile Automatic Variables ---
# $@: The name of the target.
# $^: The names of all the prerequisites (e.g., main.o math_utils.o)
# $<: The name of the first prerequisite (e.g., main.cpp)
# ------------------------------------


# --- RULES ---

# PHONY targets are not actual files. Tells `Make` that `all` and `clean` are just commands to be executed.
.PHONY: all clean

# Default rule runs when `make` command is typed in the terminal, it depends on the final executable..
all: $(TARGET)

# Rule for linking all object files into the final executable. This rule only runs if the executable is missing or an object file has been modified.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each source file into its corresponding object file.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean-up all generated files. Run with `make clean`.
clean:
	rm -f $(OBJS) $(TARGET) $(OBJS:.o=.d)

# Include the generated dependency files.  The '-' before 'include' tells `make` to continue without error if the files don't exist yet.
-include $(OBJS:.o=.d)
```

**Build:**

```shell
cd to_project_folder
# build
make
```

To clean up generated build files run:

```shell
# Note you don't have to run `make clean` every time before `make`, see the below note ↓
make clean
```

`Note:` you should run `make clean` every time you:

1. Edit the Makefile.
2. Want a clean build, weird error issues occurs.
3. Downloaded or updated external libraries that your project links against.

## CMake

-   CMAKE is a **cross-platform build system generator**. It generates **OS-specific build files** like (**Makefiles**, ninja, etc..) from a configuration file known as **CMakeLists.txt**, then those build tools (Makefiles, ninja, etc..) will execute the generated files.

[CMake Example](https://github.com/t20e/Http_Server_cpp/blob/main/CMakeLists.txt)

**Cmake Build Steps**:

```bash
# Run from project's root

# Create the build system
cmake -S . -B build
# Build & Compile
cmake --build build
# Run the executable
./build/executable
```

### Cmake With Conan Package Manager

[CMake With Conan Example](https://github.com/t20e/Http_Server_cpp/blob/main/Conanfile.py)

**Project Structuring Process:**

1. Define dependencies and generators in Conanfile.py. Generators like `CMakeDeps` and `CMakeToolchain` translate Conan's dependency information into files CMake can read.


1. Configure CMakeLists.txt

2. Standard commands to build the project.

```Bash
# EXAMPLE from a project's root

# Install dependencies & run generators
conan install . --build=missing;

# Change into build directory and load environment variables
cd build/Release;
source ./generators/conanbuild.sh;
# Capturing current environment in deactivate_conanbuildenv-release-x86_64.sh
# Configuring environment variables

# Run CMakeLists.txt configurations, passing the Conan file
cmake ../.. -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release;

# Build the executable
cmake --build .;

# Run Executable
./build/Release/executable_name;

# Cleans up the project's environment variables from the shell session.
$ source ./generators/deactivate_conanbuild.sh
```

⭐️ Or if you are using **build()** class method in the Conanfile.py:

```python
def build(self):
    cmake = CMake(self)  
    cmake.configure() 
    cmake.build()  
```

⭐️ Below commands perform all the above shell commands!

```bash
# Run this when you make changes to Conanfile.py to install any new dependencies.
conan install . --build=missing

# Run this when you repeatedly change code, i.e., you are in developer mode.
conan build . 
```
