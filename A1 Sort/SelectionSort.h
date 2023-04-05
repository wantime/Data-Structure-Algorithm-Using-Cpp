//
// Created by BsWY on 2022/9/24.
//

#ifndef PLAY_DATA_STRUCT_BY_CPP_SELECTIONSORT_H
#define PLAY_DATA_STRUCT_BY_CPP_SELECTIONSORT_H

template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; ++i) {
        // 寻找[i,n)区间的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        // swap minIndex and j
        swap(arr[i], arr[minIndex]);
//        int tmp = arr[i];
//        arr[i] = arr[minIndex];
//        arr[minIndex] = tmp;
    }
}


#endif //PLAY_DATA_STRUCT_BY_CPP_SELECTIONSORT_H
