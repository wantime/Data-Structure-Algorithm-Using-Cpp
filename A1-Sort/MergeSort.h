

#ifndef PLAY_DATA_STRUCT_BY_CPP_MERGESORT_H
#define PLAY_DATA_STRUCT_BY_CPP_MERGESORT_H

#include "InsertionSort.h"
#include <vector>
using namespace std;


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

    T *aux = new T [r - l + 1];
    //T aux[r - l + 1];
    for (int i = l; i <= r; i++)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] <= aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }
    delete aux;
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {

//    if(l >=r )
//        return;
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }


    int mid = (r+l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1])
        __merge(arr, l, mid, r);

}

template<typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n - 1);

}

template<typename T>
void mergeSortBU(T arr[], int n) {

    for (int sz = 1; sz <= n; sz += sz) {
        for (int i = 0; i + sz < n; i += sz + sz) {
            // 对 arr[i...i+sz-1]和 arr[i+sz...i+2*sz-1]进行归并
            __merge(arr, i, i + sz - 1, min(n - 1, i + sz + sz - 1));
        }
    }
    return;
}


int __mergeCount(vector<int> & arr, int l, int mid, int r) {

    vector<int> aux(r-l+1);
    for( int i = l ; i <= r ; i ++ )
        aux[i-l] = arr[i];

    // 初始化逆序数对个数 res = 0
    int res = 0;
    int i = l;
    int j = mid + 1;
    int k = l;
    // 左边的数组本身是有序的，右边的数组本身也是有序的
    // 当左边或者右边已经处理完毕，或者左边小于右边，直接并入排序数组，其他不处理
    for (int k = l; k <= r; k ++){
        if( i > mid){
            arr[k] = aux[j-l];
            j++;
        } else if( j > r){
            arr[k] = aux[i - l];
            i ++;
        } else if ( aux[i-l] <= aux[j-l]){
            arr[k] = aux[i-l];
            i ++;
        } else{
            arr[k] = aux[j-l];
            j ++;
            res += mid - i + 1;
        }
    }
    return res;
}
// 判断nums[l...mid] 与 nums[mid+1...r]这两组数据的情况，下面是分析
// 两个指针i 与 j，分别指向左边的数组与右边的数组
// 如果nums[i] > nums[j]，代表nums[i...mid]这些数值均大于nums[j]
// 逆序对增加 mid - i + 1个
int __reversePairsCount(vector<int>& nums, int l, int r){
    if (l >= r)
        return 0;

    int mid = l + (r-l)/2;

    int res1 = __reversePairsCount(nums, l, mid);
    int res2 = __reversePairsCount(nums, mid+1, r);

    return res1 + res2 + __mergeCount(nums, l, mid, r);
}

int reversePairs(vector<int>& nums) {

    return  __reversePairsCount(nums, 0, nums.size()-1);
}



#endif //PLAY_DATA_STRUCT_BY_CPP_MERGESORT_H
