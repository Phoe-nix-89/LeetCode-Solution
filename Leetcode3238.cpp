#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-number-of-winning-players/ */

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> temp(n,vector<int> (101,0));

        for(auto x : pick){
            temp[x[0]][x[1]]++;
        }

        int c =0;

        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                if(temp[i][j] >= (i+1)){
                    c++;
                    break;
                }
            }
        }

        return c;
    }
};  