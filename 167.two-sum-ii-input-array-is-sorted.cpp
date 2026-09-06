// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int32_t l = 0;
        int32_t r = numbers.size() - 1;
        while(numbers[l] + numbers[r] != target){
            if(numbers[l] + numbers[r] > target) r--;
            else l++;
        }

        return {l+1, r+1};
    }
};
// @leet end

int main() {}
