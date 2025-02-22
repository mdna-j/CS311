CC = g++                 # use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++17  # compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

SRCS = graph.cpp main.cpp   # List of source files
OBJS = $(SRCS:.cpp=.o)      # Object files corresponding to the source files
DEPS = $(SRCS:.cpp=.d)      # Dependency files

# Rule to create the program executable
prog8: $(OBJS)
	$(CC) $(OBJS) -o prog8

# Rule to compile .cpp files into .o files
.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up the generated files
clean:
	rm -f *.o prog8 $(DEPS)

# Generate dependency files
-include $(DEPS)