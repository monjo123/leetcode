// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int32_t>> ans;
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int32_t l = i + 1;
            int32_t r = nums.size() - 1;


            while(l < r){
                int32_t sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }else if(sum > 0){
                    r--;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }else{
                    l++;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return ans;
        
    }
};
// @leet end

int main() {}
