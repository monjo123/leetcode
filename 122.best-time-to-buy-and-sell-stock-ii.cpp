// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int32_t n = prices.size();
        int d[n],dp[n];
        d[0]=0;
        for(int i=1;i<n;i++) d[i]=prices[i]-prices[i-1];
        int ans=0;
        for(int i=0;i<n;i++) if(d[i]>0) ans+=d[i];
        return ans;
        
    }
};
// @leet end

int main() {}
