#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=daily-question&envId=2024-07-19 */

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,pair<int,int>> m;
        for(int j=0;j<matrix[0].size();j++){
            int ans = matrix[0][j];
            int x = 0;
            int y = j;

            for(int i=0;i<matrix.size();i++){
                if(matrix[i][j] > ans){
                    ans = matrix[i][j];
                    x = i;
                }
            }

            m[ans] = {x,y};
        }

        vector<int> temp;

        for(auto x : m){
            int ans = x.first;
            int i = x.second.first;
            for(int j=0;j<matrix[0].size();j++){
                ans = min(ans,matrix[i][j]);
            }

            if(ans == x.first) temp.push_back(ans);
        }

        return temp;
    }
};