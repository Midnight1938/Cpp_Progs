# Compiler and compiler flags
CC := g++
CFLAGS := -Wall -Wextra -pedantic -Werror -std=c++20 -O2 -g -fstack-protector-strong -fstack-protector-all -Wstack-protector -Wformat -Wformat-security -Wsign-conversion -Wshadow -Wfloat-equal -Wduplicated-cond -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat-signedness -Wformat-truncation -Wstrict-overflow -Wformat-overflow -fstack-clash-protection -fcf-protection -fsanitize=address -fsanitize=leak -fsanitize=undefined -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -D_GLIBCXX_DEBUG 

# Directories
SRC_DIR := src
OBJ_DIR := output
BIN_DIR := output

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
EXECUTABLE := $(BIN_DIR)/tetris_game

# Targets
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lncurses -lpanel -lmenu

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
