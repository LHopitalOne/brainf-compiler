# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wno-dangling-else -Wno-extra-tokens -I./include
LDFLAGS := 

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Files
TARGET := $(BIN_DIR)/brainf
SOURCES := main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SOURCES)))

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# Create directories if not exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean
