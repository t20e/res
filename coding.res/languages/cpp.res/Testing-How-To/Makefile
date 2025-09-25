# Assign variable `CXX` to the clang++ compiler
CXX = clang++

# Assign CXXFLAGS variable that defines compiler flags
# The -I tells the compiler where to look for header files (#include <...>)
# Also point to our include folder (-Iinclude), GTest's include folder (-Igoogletest/googletest/include) and GMock
# pthread is required for gtest
# -Wall enable all compiler warnings
# The `-MMD` and `-MP` flags generate dependency files (.d) that track header file changes. 
# If you modify a header file, 'make' will know to recompile the source files that include that header file.
CXXFLAGS = -std=c++17 -Wall -Iinclude -Igoogletest/googletest/include -Igoogletest/googlemock/include -Igoogletest/googletest -Igoogletest/googlemock -pthread -MMD -MP

# The name of the final executable file
TARGET = tests_exe

# A list of all C++ source (.cpp) files
SRCS = src/math_functions.cpp tests/test_math.cpp src/DatabaseHuman.cpp src/WorkManager.cpp tests/test_human.cpp

# Google test source files
GTEST_SRCS = googletest/googlemock/src/gmock_main.cc \
	googletest/googletest/src/gtest-all.cc \
	googletest/googlemock/src/gmock-all.cc

# Automatically generate a list of object (.o) files from the source files
OBJS = $(SRCS:.cpp=.o) $(GTEST_SRCS:.cc=.o) # the .cc are for the gtest-all.cc and gtest_main.cc

# --- Makefile Automatic Variables ---
# $@: The name of the target.
# $^: The names of all the prerequisites (e.g., main.o math_utils.o)
# $<: The name of the first prerequisite (e.g., main.cpp)
# ------------------------------------

# --- RULES ---

# PHONY targets are not actual files. Tells `Make` that `all` and `clean` are just commands to be executed. 
.PHONY: all clean test

# Default rule runs when `make` command is typed in the terminal, it depends on the final executable..
all: $(TARGET)

# Rule for linking all object files into the final executable. This rule only runs if the executable is missing or an object file has been modified.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each source file into its corresponding object file.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
%.o: %.cc # same but for (.cc) files
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Rule to build + run the tests, run with `make test`
test: $(TARGET)
	./$(TARGET)

# Rule to clean-up all generated files. Run with `make clean`.
clean:
	rm -f $(OBJS) $(TARGET) $(OBJS:.o=.d)


# Include the generated dependency files.  The '-' before 'include' tells `make` to continue without error if the files don't exist yet.
-include $(OBJS:.o=.d)