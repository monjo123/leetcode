// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int32_t> preMax(height.size());
        for(int i=0;i<height.size();i++){
            if(i == 0) preMax[i] = height[i];
            else preMax[i] = max(preMax[i-1], height[i]);
        }
        vector<int32_t> sufMax(height.size());
        for(int i=height.size()-1;i>=0;i--){
            if(i == height.size() - 1) sufMax[i] = height[i];
            else sufMax[i] = max(sufMax[i+1], height[i]);
        }

        int32_t ans = 0;
        for(int i=0;i<height.size();i++) ans += min(preMax[i], sufMax[i]) - height[i];

        return ans;
    }
};
// @leet end

int main() {}
