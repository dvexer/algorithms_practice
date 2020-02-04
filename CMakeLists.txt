cmake_minimum_required(VERSION 3.15)
project(algorithms_practice)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp algorithms/BinarySearch.cpp)
set(HEADERS algorithms/BinarySearch.hpp)

add_subdirectory(tests)

add_executable(algorithms_practice ${SOURCES} ${HEADERS})
