//
// Created by wy on 2023/4/14.
//

#include <vector>
#include <iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {

    int k = 0;
    for(int i = 0; i < nums.size(); i ++){
        if( nums[i] != val){
            nums[k++] = nums[i];
        }
    }
    return k;
}
