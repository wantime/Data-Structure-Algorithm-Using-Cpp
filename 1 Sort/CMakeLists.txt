cmake_minimum_required(VERSION 3.23)
project(play_data_struct_by_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(play_data_struct_by_cpp main.cpp "1 Sort/Student.h" "1 Sort/SortTestHelper.h" "1 Sort/SelectionSort.h" "1 Sort/BubbleSort.h" "1 Sort/InsertionSort.h" "1 Sort/MergeSort.h" "1 Sort/QuickSort.h" Heap.h HeapSort.h)
