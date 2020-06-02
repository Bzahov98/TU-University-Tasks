cmake_minimum_required(VERSION 3.13)
project(MultyThreadSortProject)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

#[[target_include_directories(A Utils)
target_include_directories(B Algorithms)
target_include_directories(C Algorithms/ParallelQuickSort)
target_include_directories(D Algorithms/ParallelQuickSort)]]

add_library(MultyThreadSortProject STATIC
        MainProgram.cpp
        Utils/SplitFunctions.cpp
        Utils/SplitFunctions.h
        Utils/ReadFromFile.cpp
        Utils/FileUtils.h
        Algorithms/ParallelQuickSort/ParralellQuickSort.cpp
        Algorithms/ParallelQuickSort/ParralellQuickSort.h
        Algorithms/ParallelMergeSort/MergeSort.cpp
        Algorithms/ParallelMergeSort/MergeSort.h
        )
add_executable(CMakeLists Algorithms/ParallelMergeSort/MergeSort.cpp)

add_executable(MainProgram MainProgram.cpp
        Utils/SplitFunctions.cpp
        Utils/SplitFunctions.h
        Utils/ReadFromFile.cpp
        Utils/FileUtils.h
        Algorithms/ParallelQuickSort/ParralellQuickSort.cpp
        Algorithms/ParallelQuickSort/ParralellQuickSort.h
        Algorithms/ParallelMergeSort/MergeSort.cpp
        Algorithms/ParallelMergeSort/MergeSort.h
        )
add_executable(test test.c)


add_executable(testQuicksort Algorithms/ParallelQuickSort/testQuicksort.cpp)