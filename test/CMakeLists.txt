# Enable testing with CTest
enable_testing()

# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include Google Test's CMake modules
include(GoogleTest)

# Find test files
file(GLOB TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Create test executable
add_executable(redis-lite-tests ${TEST_FILES})

# Link with Google Test and the project library
target_link_libraries(redis-lite-tests 
    GTest::gtest_main
    GTest::gmock_main
)

# Add project source files to the test executable, excluding main.cpp
file(GLOB_RECURSE PROJECT_SOURCE_FILES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Add sources to the test target
target_sources(redis-lite-tests PRIVATE ${PROJECT_SOURCE_FILES})

# Discover tests
gtest_discover_tests(redis-lite-tests)