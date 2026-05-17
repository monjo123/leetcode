// @leet imports start
#include <bits/stdc++.h>
#include <type_traits>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int32_t n = arr.size();
        stack<int32_t> dfs;
        vector<int32_t> visited(n);
        dfs.push(start);
        visited[start] = 1;
        while (dfs.size()) {
            int32_t cur = dfs.top(); dfs.pop();
            if(arr[cur] == 0) return true;
            if(cur - arr[cur] >= 0 && visited[cur - arr[cur]] == 0){
                dfs.push(cur - arr[cur]);
                visited[cur - arr[cur]] = 1;
            }
            if(cur + arr[cur] <  n && visited[cur + arr[cur]] == 0){
                dfs.push(cur + arr[cur]);
                visited[cur + arr[cur]] = 1;
            }
        }

        return false;
    }
};
// @leet end

int main() {}
