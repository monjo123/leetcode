// @leet imports start
#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int32_t n, m;
    bool ans = 0;
    void dfs(
        vector<vector<char>>& grid, 
        vector<vector<int32_t>>& depth,
        pair<int32_t, int32_t> cur,
        int32_t d, char c 
    ){
        int32_t offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto off:offsets){
            pair<int32_t, int32_t> nxt = {
                cur.first + off[0],
                cur.second + off[1]
            };
            if(
                0 <= nxt.first && nxt.first < n &&
                0 <= nxt.second && nxt.second < m &&
                grid[nxt.first][nxt.second] == c
            ){
                if(depth[nxt.first][nxt.second] == 0){
                    depth[nxt.first][nxt.second] = d + 1;
                    dfs(grid, depth, nxt, d + 1, c);
                }else{
                    if(d + 1 - depth[nxt.first][nxt.second] >= 3){
                        ans = 1;
                        return;
                    }
                }
            }
        }
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int32_t>> depth(n, vector<int32_t>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(depth[i][j] == 0){
                    depth[i][j] = 1;
                    dfs(grid, depth, {i, j}, 1, grid[i][j]);
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        //
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<depth[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        return ans;
    }
};
// @leet end

int main() {}
