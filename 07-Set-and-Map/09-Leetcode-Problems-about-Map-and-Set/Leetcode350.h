//
// Created by wangyao on 2022/11/30.
//

#ifndef INC_09_LEETCODE_PROBLEMS_ABOUT_MAP_AND_SET_LEETCODE350_H
#define INC_09_LEETCODE_PROBLEMS_ABOUT_MAP_AND_SET_LEETCODE350_H

#include <vector>
#include <iterator>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> record;
        for(int i = 0; i < nums1.size(); i ++){
            record[nums1[i]] += 1;
        }
        vector<int> res;
        for(int i = 0; i < nums2.size(); i ++){
            if(record[nums2[i]] != 0){
                res.push_back(nums2[i]);
                record[nums2[i]]--;
            }
        }
        return res;
    }
};

#endif //INC_09_LEETCODE_PROBLEMS_ABOUT_MAP_AND_SET_LEETCODE350_H
