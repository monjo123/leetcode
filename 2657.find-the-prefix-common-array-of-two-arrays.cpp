// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int32_t n = A.size();
        set<int32_t> st;
        vector<int32_t> C(n);
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            int32_t cnt = 0;
            for(int j=0;j<=i;j++)
                if(st.find(B[j]) != st.end())
                    cnt++;
            C[i] = cnt;
        }

        return C;
        
    }
};
// @leet end

int main() {}
