// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0 or n==1){
            return 0;
        }
        vector<int32_t> dp(n);
        if(s[0]=='(' and s[1]==')') dp[1]=2;
        if(n==2){ 
            return dp[1];
        }
        for(int i=2;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='(') dp[i]=dp[i-2]+2;
                else if(i-dp[i-1]-1>=0 and s[i-dp[i-1]-1]=='(') {
                    if(i-dp[i-1]-2>=0) dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                    else dp[i]=dp[i-1]+2;
                }
            }
        }

        int ans=0;
        for(int i:dp) ans=max(ans,i);

        return  ans;
        
    }
};
// @leet end

int main() {}
