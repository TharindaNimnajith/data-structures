cmake_minimum_required(VERSION 3.21)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures
        BinaryTree.cpp
        CircularArray.cpp
        DynamicGrowthArray.cpp
        LinkedList.cpp
        memory-allocation.cpp)
