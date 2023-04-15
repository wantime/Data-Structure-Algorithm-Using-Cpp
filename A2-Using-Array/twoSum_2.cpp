//
// Created by wy on 2023/4/14.
//
#include <vector>
using namespace std;

//二分查找法
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    for(int i = 0; i < numbers.size(); i ++){
        int v = target - numbers[i];

        //在这里进行二分查找
        int l = i + 1, r= numbers.size() - 1;
        // [l...r]范围内寻找v
        while(l <= r){
            int mid = l + (r - l)/2;
            if(v == numbers[mid]){
                res.push_back(i+1);
                res.push_back(mid+1);
                return res;
            }
            else if(v < numbers[mid]){
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    return res;
}

// 双指针(碰撞)
vector<int> twoSum_2(vector<int>& numbers, int target) {
    vector<int> res;
    int i = 0, j = numbers.size()-1;
    while(i < j){
        int v = numbers[i] + numbers[j];
        if(v == target){
            res.push_back(i+1);
            res.push_back(j+1);
            break;
        } else if(v > target)
            j--;
        else
            i++;
    }
    return res;
}
