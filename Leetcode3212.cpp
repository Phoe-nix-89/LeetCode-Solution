#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/ */

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<pair<int,int>>> col(grid.size(),vector<pair<int,int>> (grid[0].size()));
        vector<vector<pair<int,int>>> sub(grid.size(),vector<pair<int,int>> (grid[0].size()));

        for(int j=0;j<grid[0].size();j++){
            int x = 0, y = 0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j] == 'X') x++;
                else if(grid[i][j] == 'Y') y++;


                col[i][j] = {x,y};
            }
        }

        int c = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int x1,y1,x2,y2;
                int x = 0;
                int y = 0;
                x1 = col[i][j].first;
                y1 = col[i][j].second;

                if(j-1<0){
                    x2 = 0;
                    y2 = 0;
                }
                else{
                    x2 = sub[i][j-1].first;
                    y2 = sub[i][j-1].second;
                }

                x += (x1+x2);
                y += (y1+y2);
                sub[i][j] = {x,y};

                if(x == y && x > 0) c++;
            }
        }

        return c;
    }
};