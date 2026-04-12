// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int32_t MaxN = 100;
        const int32_t INF = 1e9;
        map<int32_t, vector<int32_t>> mp;
        vector<int32_t> check;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) == 0) mp[nums[i]] = {i};
            else{
                mp[nums[i]].push_back(i);
                if(mp[nums[i]].size() == 3) check.push_back(nums[i]);
            }
        }
        int32_t ans = INF;
        for(int i=0;i<check.size();i++){
            for(int j=0;j<mp[check[i]].size()-2;j++){
               ans = min((mp[check[i]][j+2] - mp[check[i]][j])*2, ans);
            }
        }
        return (ans == INF ? -1 : ans);
    }
};
// @leet end

int main() {}
