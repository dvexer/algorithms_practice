cmake_minimum_required(VERSION 3.15)
project(algorithms_practice)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp)
set(HEADERS algorithms/BinarySearch.hpp
            algorithms/BubbleSort.hpp
            algorithms/SelectionSort.hpp
            algorithms/DepthFirstSearch.hpp
            data_structures/Node.hpp
            )
include_directories(data_structures)

add_subdirectory(tests)

add_executable(algorithms_practice ${SOURCES} ${HEADERS})
