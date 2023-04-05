//
// Created by BsWY on 2022/9/25.
//

#ifndef PLAY_DATA_STRUCT_BY_CPP_QUICKSORT_H
#define PLAY_DATA_STRUCT_BY_CPP_QUICKSORT_H
#include <vector>
template<typename T>
int __partition(T arr[], int l, int r) {


    swap( arr[rand()%(r-l+1)+l] , arr[l] );
    T v = arr[l];

    int j = l;
    // arr[l+1...j] < v; arr[j+1...i] > v
    for (int i = l + 1; i <= r; i++) {
        if ( arr[i] < v ){
            swap(arr[j+1], arr[i]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}


template<typename T>
void __quickSort(T arr[], int l, int r) {

    if (r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }


    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
    return;
}


template<typename T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n - 1);
    return;
}

template<typename T>
int __partition2(T arr[],  int l, int r){

    int num = rand()%(r-l+1)+l;
    swap( arr[num] , arr[l] );
    T v = arr[l];
    // 循环不变量
    // 从[l+1...i) <= v; 从(j...r] >= v
    int i = l+1;
    int j = r;
    while(true){
        while(i <= r && arr[i] < v) i ++;
        while(j >= l + 1 && arr[j] > v) j --;
        if( i > j) break;
        swap(arr[i], arr[j]);
        i ++;
        j --;
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
int __partition2_1(T arr[],  int l, int r){

    int num = rand()%(r-l+1)+l;
    swap( arr[num] , arr[l] );
    T v = arr[l];
    // 循环不变量
    // 从[l+1...i) <= v; 从(j...r] >= v
    int i = l + 1;
    int j = r;
    while(i <= j){
        if(arr[i] < v) i ++;
        if(arr[j] > v) j --;
        if(i <= j && arr[i] >= v && arr[j] <= v){
            swap(arr[i], arr[j]);
            i ++;
            j --;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort2Ways(T arr[], int l, int r) {

    if (r - l <= 2){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2Ways(arr, l, p - 1);
    __quickSort2Ways(arr, p + 1, r);
    return;
}
template<typename T>
void quickSort2Ways(T arr[], int n){
    __quickSort2Ways(arr, 0, n-1);
    return;
}

template<typename T>
void __quickSort3Ways(T arr[], int l, int r){

    if (r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    //优化，初始元素随机选择
    swap( arr[rand()%(r-l+1)+l] , arr[l] );
    T v = arr[l];

    //arr[l+1...lt] < v; arr[lt+1...i-1] == v ; arr[gt...r] > v
    int lt = l;
    int gt = r+1;
    int i = l + 1;
    while( i < gt){
        if (arr[i] < v){
            swap( arr[i], arr[lt+1]);
            lt ++;
            i ++;
        } else if( arr[i] > v){
            swap( arr[i], arr[gt-1]);
            gt --;
        } else {
            i ++;
        }
    }


    swap(arr[l], arr[lt]);
    lt --;
    __quickSort3Ways(arr, l, lt);
    __quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3ways(T arr[], int n){

    srand(time(NULL));
    __quickSort3Ways( arr, 0, n-1);
}


int __findNumK(vector<int> &nums, int l, int r, int k){

    swap(nums[l], nums[rand()%(r-l+1)+l]);

    int v = nums[l];

    int i = l;
    // arr[l+1...i] < v; arr[i+1...j] > v
    for (int j = l + 1; j <= r; j++) {
        if ( nums[j] < v ){
            swap(nums[i+1], nums[j]);
            i++;
        }
    }
    swap(nums[l], nums[i]);
    int p = i;
    //int p = __quickFind(nums, l, r);

    //向一侧寻找
    if (p < nums.size() - k + 1){
        return __findNumK(nums, p+1, r, k);
    } else if (p > nums.size() - k + 1){
        return __findNumK(nums, l, p - 1, k);
    } else
        return nums[p];
}

int __findNumK2Ways(vector<int> &nums, int l, int r, int k){

    swap(nums[l], nums[rand()%(r-l+1)+l]);

    int v = nums[l];

    int i = l + 1;
    // arr[l+1...i) =< v; arr[gt...r] > v
    int gt = r + 1;
    while (i < gt){
        if (nums[i] <= v){
            i ++;
        } else{
            gt --;
            swap(nums[i], nums[gt]);
        }
    }
    i --;
    swap(nums[l], nums[i]);
    int p = i;
    //int p = __quickFind(nums, l, r);

    //向一侧寻找
    if (p < nums.size() - k ){
        return __findNumK2Ways(nums, p+1, r, k);
    } else if (p > nums.size() - k ){
        return __findNumK2Ways(nums, l, p - 1, k);
    } else
        return nums[p];
}



int findNumK(vector<int> nums, int k){
    srand(time(NULL));
    return __findNumK2Ways(nums,0, nums.size()-1, k);
}

#endif //PLAY_DATA_STRUCT_BY_CPP_QUICKSORT_H
