#include "Heap.h"
#include <vector>

#include "1 Sort/SortTestHelper.h"
#include "1 Sort/MergeSort.h"
#include "1 Sort/QuickSort.h"
#include "HeapSort.h"

template<typename T>
void __shiftDown(T arr[], int n, int k){
    while(2*k+1 < n){
        int j = 2*k+1; // 在此轮循环中,data[k]和data[j]交换位置
        if(j+1< n && arr[j] < arr[j+1])
            j = j + 1;
        if(arr[k] >= arr[j])
            break;
        swap(arr[k], arr[j]);
        k = j;
    }
}

template<typename T>
void heapSort(T arr[], int n){

    for(int i = (n-1-1)/2; i >= 0; i --)
        __shiftDown(arr, n, i);

    for(int i = n-1; i > 0; i --){
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}
// 比nums2[j]大的最小nums1[i]
void solution(vector<int>& nums1, vector<int>& nums2){


    vector<int> res;
    for (int i = 0; i < nums2.size(); i ++){
        int minCur = 0;
        for(int j = 0; j < nums1.size(); j ++){
            if(nums1[j] > nums2[i] && minCur < nums1[j] )
                minCur = nums1[j];
        }
        res.push_back(minCur);
    }
    
}
int main() {



    return 0;

}
