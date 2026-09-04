// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minOperations(string s) {
        int32_t Min = 'z' + 1;
        for(int i=0;i<s.size();i++)
            Min = (s[i] != 'a' && s[i] < Min ? s[i] : Min);
        return 'z' + 1 - Min;

        
    }
};
// @leet end

int main() {}
