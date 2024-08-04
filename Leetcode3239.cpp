#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/ */

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int c1 = 0;
        for(int i=0;i<grid.size();i++){
            int y1 = 0;
            int y2 = grid[i].size()-1;
            while(y1<y2){
                if(grid[i][y1] != grid[i][y2]) c1++;
                y1++;
                y2--;
            }
        }

        int c2 = 0;

        for(int j=0;j<grid[0].size();j++){
            int x1 = 0;
            int x2 = grid.size()-1;
            while(x1<x2){
                if(grid[x1][j] != grid[x2][j]) c2++;
                x1++;
                x2--;
            }
        }

        int ans = min(c1,c2);
        return ans;
    }
};