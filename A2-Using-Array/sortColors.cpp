//
// Created by wy on 2023/4/14.
//
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

void sortColors(vector<int>& nums) {
    int count[3] = {0};
    for( int i = 0; i < nums.size(); i ++){
        assert( nums[i] >= 0 && nums[i] <= 2);
        count[nums[i]] ++;
    }
    int index = 0;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < count[i]; j ++){
            nums[index++] = count[i];
        }
    }
}

void sortColors3way(vector<int>& nums) {
    int zero = -1; // nums[0...zero] == 0;
    int two = nums.size(); // nums[two...nums.size()-1] == 2;
    //nums[zero+1...i) == 1;
    for(int i = 0; i < two;){
        if(nums[i] == 1){
            i ++;
        } else if(nums[i] == 2){
            two --;
            swap( nums[i], nums[two]);
        }
        else {// if(nums[i] == 0){
            assert(nums[i] == 0);
            zero++;
            swap(nums[zero], nums[i]);
            i++;
        }
    }
}
