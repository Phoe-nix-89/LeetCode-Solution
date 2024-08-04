#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/design-neighbor-sum-service/ */

class neighborSum {
public:
    unordered_map<int,pair<int,int>> m;
    vector<vector<int>> temp;
    neighborSum(vector<vector<int>>& grid) {
        temp = grid;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                m[grid[i][j]] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int s = 0;
        int x = m[value].first;
        int y = m[value].second;
        if(x-1 >=0) s += temp[x-1][y];
        if(x+1<temp.size()) s += temp[x+1][y];
        if(y-1 >=0) s += temp[x][y-1];
        if(y+1 < temp[0].size()) s += temp[x][y+1];

        return s;
    }
    
    int diagonalSum(int value) {
        int s = 0;
        int x = m[value].first;
        int y = m[value].second;
        if(x-1 >=0 && y-1 >= 0) s += temp[x-1][y-1];
        if(x-1 >=0 && y+1 < temp[0].size()) s += temp[x-1][y+1];
        if(x+1 < temp.size() && y-1 >=0) s += temp[x+1][y-1];
        if(x+1 < temp.size() && y+1 < temp[0].size()) s += temp[x+1][y+1];

        return s;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */