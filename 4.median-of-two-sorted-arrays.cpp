// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int32_t n = nums1.size();
        int32_t m = nums2.size();

        int32_t i = 0, j = 0;
        double ans = 0;

        for(int k=0;k<n+m;k++){
            int32_t num;
            if(i < n && j < m){
                if(nums1[i] < nums2[j]) num = nums1[i++];
                else num = nums2[j++];
            }else{
                if(i < n) num = nums1[i++];
                else num = nums2[j++];
            }

            if((n+m)%2){
                if(k == (n+m)/2){
                    ans += num;
                    break;
                }
            }else{
                if(k == (n+m)/2-1) ans += num;
                else if(k == (n+m)/2){
                    ans = (1.0 * ans + num)/2;
                    break;
                }
            }
        }

        return ans;
    }
};
// @leet end

int main() {}
