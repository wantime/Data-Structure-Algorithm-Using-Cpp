cmake_minimum_required(VERSION 3.23)
project(play_data_struct_by_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(play_data_struct_by_cpp main.cpp "Student.h"
        "SortTestHelper.h" "SelectionSort.h" "BubbleSort.h"
        "InsertionSort.h" "MergeSort.h" "QuickSort.h"
        MaxHeap.h HeapSort.h IndexMaxHeap.h)
