// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int numberOfSpecialChars(string word) {
                
        int32_t ans = 0;
        set<char> rec;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                if(rec.find(word[i]) == rec.end() && rec.find(word[i] - 32) != rec.end()) ans++;
            }else if(isupper(word[i])){
                if(rec.find(word[i]) == rec.end() && rec.find(word[i] + 32) != rec.end()) ans++;
            }
            rec.insert(word[i]);
        }


        return ans;
    }
};
// @leet end

int main() {}
