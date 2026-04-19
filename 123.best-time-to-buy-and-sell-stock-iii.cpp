// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int32_t n = prices.size();
        const int32_t INF = 1e9;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-INF)));
        for(int i=0;i<3;i++)
            dp[0][i][0]=0;
        dp[0][0][1] =  -prices[0];
        for(int a=1;a<n;a++){
            for(int b=0;b<3;b++){
                dp[a][b][1]=max(dp[a-1][b][1],dp[a-1][b][0]-prices[a]);
                if(b!=0) dp[a][b][0]=max(dp[a-1][b][0],dp[a-1][b-1][1]+prices[a]);
                else dp[a][b][0]=dp[a-1][b][0];
            }
        }
        int ans=0;
        for(int b=0;b<3;b++) ans=max(ans,dp[n-1][b][0]);

        return ans;
    }
};
// @leet end

int main() {}
