cmake_minimum_required(VERSION 3.10)
project(redis-lite VERSION 0.1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Add executable
add_executable(redis-lite main.cpp ${SOURCE_FILES})

# Add test directory
add_subdirectory(test)