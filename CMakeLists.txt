cmake_minimum_required(VERSION 3.10..4.2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(PROJECT_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(PROJECT_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")

project(SOME_NAME VERSION 1.0 LANGUAGES CXX)

find_package(raylib REQUIRED)
# Get the headers and source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_library(memtrace "src/memtrace.cpp")

target_include_directories(memtrace PUBLIC "${PROJECT_LIB}")

# add the MEMTRACE macro definition
target_compile_definitions(memtrace PUBLIC MEMTRACE)

# Get executable
add_executable(program ${SOURCES})


# Add the following dirs
target_include_directories(program PRIVATE "${PROJECT_LIB}"
"${PROJECT_INCLUDES}")

# TODO: Add local external libs to the binary
target_link_libraries(program PRIVATE memtrace raylib)


# Compiler flags and options
target_compile_options(program PRIVATE
$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Werror>
$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

message(STATUS "System: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")
# TODO: add tests here too
# enable_testing()

