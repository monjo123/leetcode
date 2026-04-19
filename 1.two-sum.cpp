// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int32_t n = nums.size();
        pair<int32_t, int32_t> data[n];
        for(int i=0;i<n;i++) data[i] = {nums[i], i};
        sort(data, data+n);
        for(int i=0;i<n;i++){
            auto it = lower_bound(data, data+n, make_pair(target - data[i].first, 0));
            if(it != data+n && it->first == (target - data[i].first)){
                if(data[i].second == it->second) i++;
                return {it->second, data[i].second};
            }
        }
        return {-1};
    }
};
// @leet end

int main() {}
