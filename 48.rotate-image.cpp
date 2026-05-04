// @leet imports start
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    void solve(vector<vector<int>>& matrix, int32_t n, int32_t off){
        if(n <= 1) return;
        for(int k=0;k<n;k++)
            swap(matrix[k+off][0+off], matrix[0+off][n-1-k+off]);
        for(int k=1;k<n;k++)
            swap(matrix[k+off][0+off], matrix[n-1+off][k+off]);
        for(int k=1;k<n-1;k++)
            swap(matrix[n-1+off][k+off], matrix[n-1-k+off][n-1+off]);

        // for(int i=0+off;i<n+off;i++){
        //     for(int j=0+off;j<n+off;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        solve(matrix, n-2, off+1);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        solve(matrix, matrix.size(), 0);
        
        return;
    }
};
// @leet end

int main() {}
