// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int32_t i = 1;
        while(i < nums.size() && nums[i-1] == nums[i]) i++;
        return i != nums.size();
    }
};
// @leet end

int main() {}
