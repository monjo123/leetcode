// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <type_traits>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int32_t n = nums.size();
        vector<int32_t> cnt(n);
        for(int num:nums){
            if(num >= n || (++cnt[num] > 1 && num != n-1) || cnt[num] > 2){
                return false;
            }
        }
        return true;
           
    }
};
// @leet end

int main() {}
