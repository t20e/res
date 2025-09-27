# Build Automation Tool CMake vs Make

**Note**: Built on the .cpp and .h files from [importingFunctions.md](importingFunctions.md)


## Make

⭐️ [A more sophisticated makefile](https://github.com/t20e/encryptor/blob/main/Makefile)

For testing see [GTest Makefile](Testing-How-To/Makefile).

---

- A **Makefile** is a script that automates the build process, so if we have **many** external functions and dependencies, instead of linking each when compiling we can automate the process with `make`:
  - Note: we still need header files files.

`Makefile`

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
<!-- TODO -->
- CMAKE is a **build system generator**. It creates OS-specific build files like (**Makefiles**, Visual Studio projects, Xcode projects, etc...) from a single set of configuration files known as CMakeLists.txt
