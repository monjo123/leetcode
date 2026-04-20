// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int32_t n = colors.size();
        
        int32_t ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(colors[i] != colors[j]){
                    ans = max(j - i, ans);
                }
            }
        }
        return ans;
    }
};
// @leet end

int main() {}
