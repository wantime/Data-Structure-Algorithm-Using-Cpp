//
// Created by wy on 2023/4/14.
//
#include <vector>
#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
    vector<int> nonZeroElements;
    for(int i = 0; i < nums.size(); i ++)
        if( nums[i] )
            nonZeroElements.push_back(nums[i]);

    for(int i = 0; i < nonZeroElements.size(); i ++)
        nums[i] = nonZeroElements[i];

    for(int i = nonZeroElements.size(); i < nums.size(); i ++)
        nums[i] = 0;
}
// 改进1
void moveZeroes1(vector<int>& nums) {

    int index;
    for(auto num : nums){
        if( num ){
            nums[index] = num;
            index++;
        }
    }
    for(int i = index; i < nums.size(); i ++)
        nums[i] = 0;
}
//改进2
void moveZeroes2(vector<int>& nums) {

    int j = 0;
    for(int i = 0; i < nums.size(); i ++){
        if( nums[i] ){
            nums[j] = nums[i];
            if(j != i)
                nums[i] = 0;
            j++;
        }
    }
}
//改进3
void moveZeroes3(vector<int>& nums) {

    int k = 0; // nums[0..k)的元素为非零元素
    // 遍历到第i个元素后，保证[0...i]中所有非0元素
    // 都按照顺序排列在[0...k)中
    for(int i = 0; i < nums.size() ; i ++){
        if( nums[i] )
            if( i != k )
                swap(nums[k++], nums[i]);
            else
                k++;
    }
}