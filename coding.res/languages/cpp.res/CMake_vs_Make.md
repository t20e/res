# Build Automation Tool CMake vs Make

**Note**: Built on the .cpp and .h files from [importingFunctions.md](importingFunctions.md)


## Make

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

****
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

## CMake
<!-- TODO -->
- CMAKE is a **build system generator**. It creates OS-specific build files like (**Makefiles**, Visual Studio projects, Xcode projects, etc...) from a single set of configuration files known as CMakeLists.txt

