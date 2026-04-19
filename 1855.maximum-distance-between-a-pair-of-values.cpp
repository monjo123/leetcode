// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int32_t n = nums1.size();
        int32_t m = nums2.size();
        
        for(int i=0;i<m/2;i++) 
            swap(nums2[i], nums2[m - 1 - i]);

        int32_t ans = 0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
            ans = max(m - 1 - (int32_t)(it - nums2.begin()) - i, ans);
            
            // cout<<(int32_t)(it - nums2.begin())<<"\n";
        }

        return ans;
    }
};
// @leet end

int main() {}
