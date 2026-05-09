// @leet imports start
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int32_t n = grid.size();
        int32_t m = grid[0].size();
        int32_t Min = min(n, m);

        for(int layer=0;layer<Min/2;layer++){
            int32_t shift = k % ((m + n - 4 - layer * 4) * 2 + 4);
            while(shift-- > 0){
                for(int j=layer+1;j<m-layer;j++)
                    swap(grid[layer][j], grid[layer][j-1]);
                for(int i=layer+1;i<n-layer;i++)
                    swap(grid[i][m-1-layer], grid[i-1][m-1-layer]);
                for(int j=m-1-layer-1;j>=layer;j--)
                    swap(grid[n-1-layer][j], grid[n-1-layer][j+1]);
                for(int i=n-1-layer-1;i>layer;i--)
                    swap(grid[i][layer], grid[i+1][layer]);
                
            }
        }

        return grid;
    }
};
// @leet end

int main() {}
