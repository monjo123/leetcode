// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int32_t l = 0, r = 0, u = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
            else if(moves[i] == '_') u++;
        }

        int32_t ans = 0;
        if(l > r) ans = abs(r - (l + u));
        else ans = abs(r + u -l);

        return ans;
    }
};
// @leet end

int main() {}
