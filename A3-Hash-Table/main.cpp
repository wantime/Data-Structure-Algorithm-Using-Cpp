#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    // leetcode 349
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> record( nums1.begin(), nums1.end());
//        for(int i = 0; i < nums1[i]; i ++)
//          record.insert(nums1[i]);

        unordered_set<int> resultSet;
        for(int i = 0; i < nums2.size(); i ++)
            if( record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);
//        vector<int> res();
//        for(set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter ++)
//            res.push_back(*iter);
//        return res;
        return vector<int>(resultSet.begin(), resultSet.end());
    }
    // leetcode 349 using map
    vector<int> intersection_map(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> record;
        for(int i = 0; i < nums1[i]; i ++)
            record[nums1[i]] ++;
        vector<int> res;
        for(int i = 0; i < nums2.size(); i ++)
            if( record[nums2[i]] != 0){
                record[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        return res;

    }

    // leetcode 202 set
    bool isHappy(int n) {
        unordered_set<int> record;
        int num = n;
        while(true){
            record.insert(num);
            int tmp = 0;
            while(num != 0){
                tmp += (num%10)*(num%10);
                num /= 10;
            }
            num = tmp;
            if( num == 1)
                return true;
            else if(record.find(num) != record.end())
                return false;
        }
    }

    // leetcode 290
    bool wordPattern(string pattern, string s) {


        vector<string> strs;
        for(int i = 0; i < s.size();){
            int j = i;
            while(s[j] != ' ' && j < s.size()) j ++;
            strs.push_back(s.substr(i, j-i));
            cout << s.substr(i, j-i) << endl;
            i = j + 1;
        }

        // 构建一个map,key为pattern的字母，value为s里的单词
        unordered_map<char, string> rec;
        // 同时构建一个set, 防止同一个单词对应多个字母
        set<string> mySet;
        int n = pattern.size();
        if(n != strs.size())
            return false;
        for(int i = 0; i < n; i ++){

            if(rec.find(pattern[i]) == rec.end()){
                if(mySet.find(strs[i]) != mySet.end())
                    return false;
                rec[pattern[i]] = strs[i];
                mySet.insert(strs[i]);
            }
            else if(rec[pattern[i]] != strs[i])
                return false;
        }
        return true;
    }

    string frequencySort(string s){
        map<char, int> freq;
        for(auto &ch : s)
            freq[ch]++;
        vector<pair<char, int>> vec;
        for(auto &it : freq)
            vec.emplace_back(it);
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second > b.second;
        });
        string ret;
        for(auto &[ch, num] : vec){
            for(int i = 0; i < num; i ++)
                ret.push_back(ch);
        }
        return ret;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> rec;
        for(int i = 0; i < nums.size(); i ++){
            rec[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i ++){
            int sub = target - nums[i];
            if(rec.find(sub) != rec.end() && rec[sub] != i){
                res.push_back(i);
                res.push_back(rec[sub]);
                return res;
            }
        }
        return res;

    }
    // Leetcode 1
    vector<int> twoSum_2(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> rec;
        for(int i = 0; i < nums.size(); i ++){
            int sub = target - nums[i];
            if(rec.find(sub) != rec.end()){
                res.push_back(i);
                res.push_back(rec[sub]);
                return res;
            }
            rec[nums[i]] = i;
        }
        return res;

    }
    // leetcode 16
    int threeSumClosest(vector<int>& nums, int target) {
        // TODO
    }
    // leetcode 454
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> rec;
        for(int i = 0; i < nums3.size(); i ++)
            for(int j = 0; j < nums4.size(); j ++)
                rec[nums3[i] + nums4[j]] ++;

        int res = 0;
        for(int i = 0; i < nums1.size(); i ++)
            for(int j = 0;j < nums2.size(); j ++)
                if( rec.find(0 - nums1[i] - nums2[j]) != rec.end())
                    res += rec[0 - nums1[i] - nums2[j]];
        return res;
    }

    // leetcode 49
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& str : strs){
            string key =str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto it = mp.begin(); it != mp.end(); it ++)
            res.emplace_back(it->second);
        return res;
    }
    // leetcode 447
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for(int i = 0; i < points.size(); i ++){
            unordered_map<int, int> rec; // key:distance, value: 点的数量
            for(int j = 0; j < points.size(); j ++ )
                if ( j != i)
                    rec[dis(points[i], points[j])] ++;
            for(auto &iter:rec)
                res += iter.second * (iter.second-1);
        }
        return res;
    }
    int dis(const vector<int> &pa, const vector<int> &pb){
        return  (pa[0] - pb[0]) * (pa[0] - pb[0]) +
                (pa[1] - pb[1]) * (pa[1] - pb[1]);
    }
    // leetcode 219
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> rec;
        for(int i = 0; i < nums.size(); i ++){

            if(rec.find(nums[i]) != rec.end())
                return true;

            rec.insert( nums[i]);

            //保持record中最多有k个元素
            if( rec.size() == k + 1)
                rec.erase( nums[i-k] );
        }
        return false;
    }
    // leetcode 219
    bool containsNearbyDuplicate_map(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        for(int i = 0; i < nums.size(); i ++){
            if(rec.find(nums[i]) != rec.end() && i - rec[nums[i]] <= k)
                return true;
            else
                rec[nums[i]] = i;
        }
        return false;
    }
    // leetcode 220
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> rec;
        for(int i = 0; i < nums.size(); i ++){
            if( rec.lower_bound( (long long)nums[i] - (long long)valueDiff) != rec.end() && *rec.lower_bound((long long)nums[i] - (long long)valueDiff) <= (long long)nums[i] + (long long)valueDiff)
                return true;
            rec.insert( nums[i] );
            if( rec.size() == indexDiff + 1)
                rec.erase( nums[i-indexDiff]);
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate_2(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> rec;
        for(int i = 0; i < nums.size(); i ++){
            if(rec.find(nums[i]) != rec.end() && i - rec[nums[i]] <= indexDiff)
                return true;
            else
                rec[nums[i]] = i;
        }
        return false;
    }
};
int main() {

    string p = "abaaba";
    string s= "dog cat fish fish cat dog";
    (new Solution())->wordPattern(p, s);

    return 0;
}
