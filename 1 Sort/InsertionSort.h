//
// Created by BsWY on 2022/9/24.
//

#ifndef PLAY_DATA_STRUCT_BY_CPP_INSERTIONSORT_H
#define PLAY_DATA_STRUCT_BY_CPP_INSERTIONSORT_H


template<typename T>
void insertionSort(T arr[], int n){

    for (int i = 1; i < n; ++i) {

        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e ; --j)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

// 对arr数组中[l...r]范围内的数进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r) {

    for (int i = l+1; i <= r; i++) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }

    return;
}
#endif //PLAY_DATA_STRUCT_BY_CPP_INSERTIONSORT_H
