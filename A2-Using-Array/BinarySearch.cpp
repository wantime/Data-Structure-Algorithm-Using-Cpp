
#include <iostream>
#include <cassert>

using namespace std;

// 二分查找法，在有序数组arr中，查找target
template<typename T>
int binarySearch(T arr[], int n, T target){
    // 在arr[l...r]之中查找target
    int l = 0 , r = n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target)
            return mid;
            // 在arr[l, mid-1]之中查找target
        else if (target < arr[mid])
            r = mid - 1;
            // 在arr[mid+1, r]之中查找target
        else
            l = mid + 1;
    }
    return -1;
}

// 修改r的定义
template<typename T>
int binarySearch_2(T arr[], int n, T target){
    // 在arr[l...r)之中查找target
    int l = 0 , r = n;
    while(l < r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            r = mid;    // 在arr[l, mid)之中查找target
        else
            l = mid + 1; // 在arr[mid+1, r)之中查找target
    }
    return -1;
}


// 二分查找法的递归实现
template<typename T>
int binarySearch_recursion(T arr[], int l, int r, T target){
    if ( l > r)
        return -1;
    int mid = l + (r-l)/2;
    if(arr[mid] == target)
        return mid;
    else if(target < arr[mid])
        return binarySearch_recursion(arr, l, mid-1, target);
    else
        return binarySearch_recursion(arr, mid+1, r, target);
}

// 二分查找法的floor方法
template<typename T>
int floor(T arr[], int n, T target){

    assert( n >= 0);

    // 在arr[l+1, r]的范围内寻找target
    int l = -1, r = n-1;
    while(l < r){

        int mid = l + (r-l+1)/2;
        std::cout << "l : " << l << "  r:" << r<< "  mid:" << mid << std::endl;
        if(arr[mid] >= target)
            r = mid - 1;
        else
            l = mid;
    }
    assert(l == r);
    if(l+1 < n && arr[l+1] == target)
        return l + 1;
    return l;
}

template<typename T>
int ceil(T arr[], int n, T target){

    assert( n >= 0);
    //arr[l,r)
    int l = 0, r = n;
    while(l < r){
        int mid = l + (r-l)/2;
        if(target >= arr[mid])
            l = mid + 1;
        else
            r = mid;
    }

    assert(l == r);
    if(r-1 >= 0 && arr[r-1] == target)
        return r - 1;
    return r;
}
