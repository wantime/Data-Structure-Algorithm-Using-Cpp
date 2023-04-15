//
// Created by w on 2023/4/15.
//
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(s.size() < p.size())
        return res;


    int freq_p[26] = {0};
    for(int i = 0; i < p.size(); i ++)
        freq_p[p[i] - 'a'] ++;

    int l = 0, r = -1;
    int freq_s[26] = {0};
    while(r + 1 < s.size()){

        if(r - l + 1 < p.size())
            freq_s[s[++r]-'a'] ++;

        while(freq_s[s[r]-'a'] > freq_p[s[r]-'a'] && l < s.size())
            freq_s[s[l++]-'a'] --;

        if( r-l+1 == p.size()){
            res.push_back(l);
            freq_s[s[l++]-'a'] --;
        }
    }
    return res;
}