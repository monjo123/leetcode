// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int32_t n = nums.size();
        vector<long long> ans(n);
        map<int32_t, vector<int32_t>> idx;
        map<int32_t, vector<int64_t>> sum;

        for(int i=0;i<n;i++){
            idx[nums[i]].push_back(i);
            sum[nums[i]].push_back((sum[nums[i]].size() ? sum[nums[i]].back() : 0) + i);
        }
        
        for(int i=0;i<n;i++){
            int32_t k = lower_bound(idx[nums[i]].begin(), idx[nums[i]].end(), i) - idx[nums[i]].begin();
            int64_t right = sum[nums[i]].back() - sum[nums[i]][k] - (sum[nums[i]].size() - 1 - k) * i;
            int64_t left = 1LL * k * i - (k ? sum[nums[i]][k-1] : 0);
            ans[i] = right + left;
        }
        
        return ans;
    }
};
// @leet end

int main() {}
