//
// Created by wangyao on 2022/11/30.
//

#ifndef INC_09_LEETCODE_PROBLEMS_ABOUT_MAP_AND_SET_LEETCODE349_H
#define INC_09_LEETCODE_PROBLEMS_ABOUT_MAP_AND_SET_LEETCODE349_H


#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> *set1 = new set<int>();
        for(int num1 : nums1){
            set1->insert(num1);
        }
        vector<int> list;
        for(int num2 : nums2){
            for(set<int>::iterator iterator1 = set1->begin(); iterator1 != set1->end();iterator1++){
                if(*iterator1 == num2){
                    list.push_back(num2);
                    set1->erase(num2);
                }

            }
        }
        return list;
    }
};

#endif //INC_09_LEETCODE_PROBLEMS_ABOUT_MAP_AND_SET_LEETCODE349_H
