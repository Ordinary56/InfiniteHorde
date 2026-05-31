cmake_minimum_required(VERSION 3.10..4.2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(PROJECT_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(PROJECT_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")

project(INFINITEHORDE VERSION 1.0 LANGUAGES CXX)

find_package(raylib CONFIG)
# Get the headers and source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_library(memtrace "src/memtrace.cpp")

target_include_directories(memtrace PUBLIC "${PROJECT_LIB}")

# add the MEMTRACE macro definition
target_compile_definitions(memtrace PRIVATE MEMTRACE)

#only compile main program if raylib exists
if(raylib_FOUND)
	message(STATUS "Raylib found. Building main program")
	# Get executable
	add_executable(program ${SOURCES})


	# Add the following dirs
	target_include_directories(program PRIVATE "${PROJECT_LIB}"
"${PROJECT_INCLUDES}")

	# TODO: Add local external libs to the binary
	target_link_libraries(program PRIVATE memtrace raylib)

	target_compile_definitions(program PRIVATE MEMTRACE)


	# Compiler flags and options
	target_compile_options(program PRIVATE
$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Werror>
$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)
else()
	message(STATUS "Raylib not found. Building test program")
endif()

message(STATUS "System: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")

# TODO: add tests here
enable_testing()
set(TEST_SOURCES ${SOURCES})
list(FILTER TEST_SOURCES EXCLUDE REGEX "main\\.cpp$")
list(FILTER TEST_SOURCES EXCLUDE REGEX "[Rr]aylib.*\\.cpp$")
add_executable(GAME_TESTS "tests/main_test.cpp" ${TEST_SOURCES})
target_include_directories(GAME_TESTS PRIVATE "${PROJECT_LIB}"
		"${PROJECT_INCLUDES}")
target_link_libraries(GAME_TESTS PRIVATE memtrace )
target_compile_definitions(GAME_TESTS PRIVATE CPORTA MEMTRACE)
target_compile_options(GAME_TESTS PRIVATE
$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Werror>
$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)
add_test(NAME infinite_horde_tests COMMAND game_tests)


