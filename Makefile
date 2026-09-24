CC = gcc

# Directories
BIN_DIR = bin/
SRC_DIR = src/
INCLUDE_DIR = include/

# Files
BIN_NAME = joncailu

# Sources
SOURCES = $(wildcard $(SRC_DIR)*.c)

# Targets
TARGET = $(BIN_DIR)$(BIN_NAME)


.PHONY: build clean

build: $(TARGET)

clean:
	rm -fr $(BIN_DIR)*

$(TARGET): $(SOURCES) | $(BIN_DIR)
	$(CC) -I. -o $@ $(SOURCES)

$(BIN_DIR):
	mkdir -p $@
