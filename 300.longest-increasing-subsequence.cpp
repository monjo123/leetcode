// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int32_t n = nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int ans=0;
        for(int &i:dp) ans=max(ans,i);
        
        return ans;

    }
};
// @leet end

int main() {}
