// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int32_t n = nums1.size();
        int32_t m = nums2.size();

        vector<vector<int>> dp(n,vector<int>(m));
        //int dp[n][m];
        dp[0][0]=(nums1[0]==nums2[0])? 1 : 0 ;
        for(int i=0;i<n;i++) if(nums1[i]==nums2[0]) dp[i][0]=1;
        for(int i=0;i<m;i++) if(nums1[0]==nums2[i]) dp[0][i]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums1[i]==nums2[j]) dp[i][j]=dp[i-1][j-1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for( int j=0;j<m;j++)
                ans=max(ans,dp[i][j]);
        return ans;
        
    }
};
// @leet end

int main() {}
