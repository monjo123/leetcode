// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int32_t n = prices.size();
        int32_t Min = prices[0], ans = 0;
        for(int i=0;i<n;i++){
            Min = min(Min, prices[i]);
            ans = max(ans, prices[i] - Min);
        }
        
        return ans;
        
    }
};
// @leet end

int main() {}
