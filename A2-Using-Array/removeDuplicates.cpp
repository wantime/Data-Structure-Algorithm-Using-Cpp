//
// Created by wy on 2023/4/14.
//
#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    if(nums.size() == 0)
        return 0;
    int k = 0; // [0...k]存储的是单独的元素，
    for(int i = 0; i < nums.size(); i ++){
        if(nums[i] != nums[k]){
            k++;
            nums[k] = nums[i];
        }
    }
    return k+1;
}
