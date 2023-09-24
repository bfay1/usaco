CXX=         g++
CXXFLAGS=    -x c++ -g -O2 -std=c++20 -Wall \
	     -fsanitize=address -fsanitize=undefined \
	     -D_GLIBCXX_DEBUG -D_GLIBCXX_ASSERTIONS

# Default target: compile and run the program
all: compile_and_run

# Compile the C++ source file into an executable
compile_and_run: $(SRC).cpp
	$(CXX) $(CXXFLAGS) -o $(basename $(SRC)) $(SRC).cpp
	./$(basename $(SRC))

# Clean up the generated files
clean:
	rm -f $(basename $(SRC)) *.out *.o

.PHONY: all compile_and_run clean
