# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
INCLUDES = -Iinclude -Itests
LDFLAGS =

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
BUILD_DIR = build
OBJ_DIR = obj

# Target executable names
TARGET = $(BUILD_DIR)/merge-sort
TEST_TARGET = $(BUILD_DIR)/test_runner

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
MAIN_OBJ = $(OBJ_DIR)/main.o
LIB_OBJECTS = $(filter-out $(MAIN_OBJ),$(OBJECTS))

# Test files
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/test_%.o,$(TEST_SOURCES))

# Default target
.PHONY: all
all: $(TARGET)

# Build main executable
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

# Build test executable
$(TEST_TARGET): $(TEST_OBJECTS) $(LIB_OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) $(LIB_OBJECTS) -o $@ $(LDFLAGS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile test files
$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create directories if they don't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run tests
.PHONY: test
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/*.o $(BUILD_DIR)/*

# Clean everything including directories
.PHONY: distclean
distclean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

# Run the main program
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Help target
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all        - Build the main executable (default)"
	@echo "  test       - Build and run tests"
	@echo "  clean      - Remove build artifacts"
	@echo "  distclean  - Remove all generated files and directories"
	@echo "  run        - Build and run the main executable"
	@echo "  help       - Show this help message"
