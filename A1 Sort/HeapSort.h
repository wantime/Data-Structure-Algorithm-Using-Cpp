//
// Created by BsWY on 2022/9/29.
//

#ifndef PLAY_DATA_STRUCT_BY_CPP_HEAPSORT_H
#define PLAY_DATA_STRUCT_BY_CPP_HEAPSORT_H
#include "Heap.h"
template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; i++)
        maxHeap.insert(arr[i]);

    for (int i = 0; i < n; i++)
        arr[n - i - 1] = maxHeap.extractMax();
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
    for (int i = 0; i < n; i++)
        arr[n-i-1] = maxHeap.extractMax();
}
#endif //PLAY_DATA_STRUCT_BY_CPP_HEAPSORT_H
