cmake_minimum_required(VERSION 3.5.1)
set(target algorithms_practice_test)

set(CMAKE_CXX_STANDARD 14)

# Download and unpack googletest at configure time
configure_file(GoogleTest-CMakeLists.txt.in ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

include_directories(${CMAKE_SOURCE_DIR})
set(SOURCES main.cpp BinarySearchTest.cpp BubbleSortTest.cpp SelectionSortTest.cpp DepthFirstSearchTest.cpp)

add_executable(${target} ${SOURCES})
target_link_libraries(${target} gtest_main)
