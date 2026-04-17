// @leet imports start
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int32_t dis(int32_t a, int32_t b, int32_t n){
        if(a > b) swap(a, b);
        return min(b - a, n + a - b);
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int32_t n = nums.size();
        int32_t m = queries.size();
        map<int32_t, set<int32_t>> index;
        for(int i=0;i<n;i++) index[nums[i]].insert(i);

        vector<int32_t> ans(m);
        for(int i=0;i<m;i++){
            if(index[nums[queries[i]]].size() < 2) ans[i] = -1;
            else{
                auto it = index[nums[queries[i]]].lower_bound(queries[i]);
                auto pre = (it == index[nums[queries[i]]].begin() ? *prev(index[nums[queries[i]]].end()) : *prev(it));
                auto nxt = (next(it) == index[nums[queries[i]]].end() ? *index[nums[queries[i]]].begin() : *next(it));
                if(dis(pre, *it, n) > dis(*it, nxt, n)) 
                    ans[i] = dis(*it, nxt, n);
                else 
                    ans[i] = dis(pre, *it, n);
            }
        }

        return ans;
        
    }
};
// @leet end

int main() {}
