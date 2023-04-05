//
// Created by BsWY on 2022/9/24.
//

#ifndef PLAY_DATA_STRUCT_BY_CPP_BUBBLESORT_H
#define PLAY_DATA_STRUCT_BY_CPP_BUBBLESORT_H


template<typename T>
void bubbleSort(T arr[], int n){
    // 每次判断j与j+1，把大的数字向后传递
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1 ; ++j) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}



#endif //PLAY_DATA_STRUCT_BY_CPP_BUBBLESORT_H
