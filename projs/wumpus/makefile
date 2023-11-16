# Variables
CC=g++
CFLAGS=-std=c++11 -g
EXE=wump
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

# Default target
all: $(EXE)

# Linking
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(EXE) $(OBJ)

.PHONY: all clean