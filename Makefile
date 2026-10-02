.PHONY: build, tests

build:
	cmake -B build && cmake --build build

compile_commands: build
	ln -s $(shell pwd)/build/compile_commands.json compile_commands.json

tests: build
	cmake --build build
	cd build && ctest

testsv: build
	cmake --build build
	cd build && ctest --verbose
