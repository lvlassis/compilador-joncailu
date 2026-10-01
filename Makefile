.PHONY: build

build:
	cmake -B build && cmake --build build

compile_commands: build
	ln -s $(shell pwd)/build/compile_commands.json compile_commands.json
