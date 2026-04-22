// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<dictionary.size();j++){
                int32_t edit = 0;
                for(int k=0;queries[i][k] != '\0';k++){
                    if(queries[i][k] != dictionary[j][k]) edit++;
                }
                if(edit <= 2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
// @leet end

int main() {}
