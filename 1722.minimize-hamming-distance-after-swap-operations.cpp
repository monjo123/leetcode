// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<int32_t> par = vector<int32_t>(100001, -1);
    vector<int32_t> size = vector<int32_t>(100001, 1);
    multiset<int32_t> cnt[100001];
    
    int32_t find(int32_t a){
        if(par[a] == -1) return a;
        else return par[a] = find(par[a]);
    }
    void merge(int32_t a, int32_t b){
        int32_t parA = find(a);
        int32_t parB = find(b);
       
        if(parA == parB) return;

        if(size[parA] >= size[parB]){
            par[parB] = parA;
            size[parA] += size[parB];
        }else{
            par[parA] = parB;
            size[parB] += size[parA];
        }

        return;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        for(int i=0;i<allowedSwaps.size();i++)
            merge(allowedSwaps[i][0], allowedSwaps[i][1]);
        for(int i=0;i<source.size();i++)
            cnt[find(i)].insert(source[i]);
        
        // for(int i=0;i<source.size();i++) cout<<par[i]<<" ";
        // cout<<"\n";

        int32_t ans = 0;
        for(int i=0;i<target.size();i++){
            auto it = cnt[find(i)].find(target[i]);
            if(it == cnt[find(i)].end()) ans++;
            else cnt[find(i)].erase(it);
        }

        return ans;
    }
};
// @leet end

int main() {}
