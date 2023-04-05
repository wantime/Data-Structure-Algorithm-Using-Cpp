//
// Created by wangyao on 2023/1/7.
//

#ifndef INC_08_PRIORITY_QUEUE_IN_CPP_SOLUTION_H
#define INC_08_PRIORITY_QUEUE_IN_CPP_SOLUTION_H

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;

        for (int num: nums)
            freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++){
            if(pq.size() == k){
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            }else{
                pq.push(make_pair(iter->second, iter->first));
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

};

#endif //INC_08_PRIORITY_QUEUE_IN_CPP_SOLUTION_H
