//
// Created by wy on 2023/4/14.
//

#include <vector>

using namespace std;


int partition(vector<int>& nums, int l, int r, int k){
    int v = nums[l];
    // [l+1...gt]存放<v的数
    // [gt+1,i]存放>v的数
    int gt = l;
    for(int i = l+1; i <= r; i ++){
        if(nums[i] < v){
            swap(nums[++gt], nums[i]);
        }
    }
    // [l+1...gt] < v
    // [gt+1...r] > v
    swap(nums[gt], nums[l]);
    // [l...gt-1] < v
    // [gt+1...r] > v
    if(gt == k)
        return v;
    else if(gt > k)
        return partition(nums, l, gt-1, k);
    else
        return partition(nums, gt+1, r, k);
}

int findKthLargest(vector<int>& nums, int k) {

    return partition(nums, 0, nums.size()-1, k);

}
