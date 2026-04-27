// @leet imports start
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    bool ans = 0;
    bool leftOK(int32_t a){
        return (a == 1 || a == 3 || a == 5);
    }
    bool rightOK(int32_t a){
        return (a == 1 || a == 4 || a == 6);
    }
    bool upperOK(int32_t a){
        return (a == 2 || a == 5 || a == 6);
    }
    bool lowerOK(int32_t a){
        return (a == 2 || a == 3 || a == 4);
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int32_t>>& visited, pair<int32_t, int32_t> cur){
        cout<<cur.first<<" "<<cur.second<<"\n";

        int32_t n = grid.size();
        int32_t m = grid[0].size();

        if(cur.first == n-1 && cur.second == m-1){
            ans = 1;
            return;
        }
        
        if(
            cur.first + 1 < n && visited[cur.first + 1][cur.second] == 0 &&
            lowerOK(grid[cur.first][cur.second]) &&
            upperOK(grid[cur.first + 1][cur.second])
        ){
            visited[cur.first + 1][cur.second] = 1;
            dfs(grid, visited, {cur.first + 1, cur.second});
            visited[cur.first + 1][cur.second] = 0;
        }
        if(
            cur.second + 1 < m && visited[cur.first][cur.second + 1] == 0 &&
            rightOK(grid[cur.first][cur.second]) &&
            leftOK(grid[cur.first][cur.second + 1])
        ){
            visited[cur.first][cur.second + 1] = 1;
            dfs(grid, visited, {cur.first, cur.second + 1});
            visited[cur.first][cur.second + 1] = 0;
        }
        if(
            0 <= cur.first - 1 && visited[cur.first - 1][cur.second] == 0 &&
            upperOK(grid[cur.first][cur.second]) &&
            lowerOK(grid[cur.first - 1][cur.second])
        ){
            visited[cur.first - 1][cur.second] = 1;
            dfs(grid, visited, {cur.first - 1, cur.second});
            visited[cur.first - 1][cur.second] = 0;
        }
        if(
            0 <= cur.second - 1 && visited[cur.first][cur.second - 1] == 0 &&
            leftOK(grid[cur.first][cur.second]) &&
            rightOK(grid[cur.first][cur.second - 1])
        ){
            visited[cur.first][cur.second - 1] = 1;
            dfs(grid, visited, {cur.first, cur.second - 1});
            visited[cur.first][cur.second - 1] = 0;
        }
        return;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int32_t n = grid.size();
        int32_t m = grid[0].size();
        
        vector<vector<int32_t>> visited(n, vector<int32_t>(m));
        
        visited[0][0] = 1;
        dfs(grid, visited, {0, 0});
        
        return  ans;
    }
};
// @leet end

int main() {}
