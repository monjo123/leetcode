// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int32_t num = n;
        int32_t sum = 0;
        while(num){
            if(num % 10 == 0) sum += 1;
            else{
                int32_t tmp = 1;
                for(int i=1;i<=num%10;i++) tmp *= i;
                sum += tmp;
                // cout<<tmp<<"\n";
            }
            num /= 10;
        }

        multiset<int32_t> st;
        while(sum){
            st.insert(sum % 10);
            sum /= 10;
        }
        // for(auto i:st) cout<<i<<" ";
        // cout<<"\n";
        while(n){
            auto it = st.find(n % 10);
            if(it == st.end()) return false;
            st.erase(it);
            n /= 10;
        }
        
        return (st.size() == 0);
    }
};
// @leet end

int main() {}
