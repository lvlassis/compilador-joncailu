cmake_minimum_required(VERSION 3.16)
project(joncailu C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.c")

add_executable(joncailu ${SOURCES})
target_include_directories(joncailu PRIVATE ${CMAKE_SOURCE_DIR})

set_target_properties(joncailu PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
