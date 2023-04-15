//
// Created by w on 2023/4/15.
//
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, r = -1;
    int freq[256] = {0};
    int res = 0;
    while(l < s.size()){
        if(r+1 < s.size() && freq[s[r+1]] == 0)
            freq[s[++r]]++;
        else
            freq[s[l++]]--;
        res = max(res, r-l+1);
    }
    return res;
}
