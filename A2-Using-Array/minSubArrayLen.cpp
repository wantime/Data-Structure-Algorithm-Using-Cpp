//
// Created by w on 2023/4/15.
//
#include <vector>
#include <iostream>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {

    int i = 0, j = -1; // nums[i...j]->滑动窗口
    int minLen = nums.size()+1;
    int sum = 0;
    while (i < nums.size()){

        if(j+1 < nums.size() && sum < target)
            sum += nums[++j];
        else
            sum -= nums[i++];

        if(sum >= target)
            minLen = min(minLen, j-i+1);
    }
    return minLen == nums.size() + 1 ? 0 : minLen;
}