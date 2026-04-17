// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <utility>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        const int32_t INF = 1e9;
        
        int32_t n = nums.size();
        map<int32_t, set<int32_t>> index;

        for(int i=0;i<n;i++) index[nums[i]].insert(i);

        int32_t ans = INF;
        for(int i=0;i<n;i++){
            int32_t num = nums[i];
            int32_t target = 0;
            while(num){
                target = target * 10 + num % 10;
                num /= 10;
            }

            auto it = index[target].upper_bound(i);
            if(it != index[target].end())
                ans = min(*it - i, ans);
        }

        return (ans == INF ? -1 : ans);
        
    }
};
// @leet end

int main() {}
