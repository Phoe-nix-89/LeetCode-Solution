#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/ */

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            int x = startPos[0];
            int y = startPos[1];
            int c = 0;
            for(int j=i;j<s.length();j++){

                if(s[j] == 'R'){
                    if(y+1<n) y++;
                    else break;
                }
                else if(s[j] == 'L'){
                    if(y-1>=0) y--;
                    else break;
                }
                else if(s[j] == 'U'){
                    if(x-1>=0) x--;
                    else break;
                }
                else if(s[j] == 'D'){
                    if(x+1<n) x++;
                    else break;
                }

                c++;
            }

            ans.push_back(c);
        }

        return ans;
    }
};