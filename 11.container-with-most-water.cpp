// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int32_t l = 0;
        int32_t r = height.size() - 1;
        int32_t ans = 0;

        while(l < r){
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};
// @leet end

int main() {}
