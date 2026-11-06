cmake_minimum_required(VERSION 3.10)
# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# used internally by CMake to identify your project
project(a10)
# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)
# Add the main executable
add_executable(a10 src/main.cpp)
# Add the test executable
add_executable(my_test tests/test_stack_queue_utils.cpp)
# target_include_directories(my_test PRIVATE ${CMAKE_SOURCE_DIR}/tests)
# Enable testing
enable_testing()
# Register the test executable with CTest (optional)
add_test(NAME my_test COMMAND my_test)