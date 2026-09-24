CC = gcc

# Directories
BIN_DIR = bin/
SCANNER_DIR = scanner/

# Files
SCANNER_FILE_NAME = scanner

# Sources
SCANNER_SOURCE = $(SCANNER_DIR)$(SCANNER_FILE_NAME).c

# Targets
SCANNER_TARGET = $(BIN_DIR)$(SCANNER_FILE_NAME)


.PHONY: scanner clean

scanner: $(SCANNER_TARGET)

clean:
	rm -fr $(BIN_DIR)*

$(SCANNER_TARGET): $(SCANNER_SOURCE) | $(BIN_DIR)
	$(CC) -o $@ $^

$(BIN_DIR):
	mkdir -p $@

