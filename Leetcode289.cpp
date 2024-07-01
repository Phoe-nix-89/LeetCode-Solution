
/* https://leetcode.com/problems/game-of-life/description/ */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> arr(n,vector<int> ());
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int x = i-1;
                int y = j-1;
                int t1 = x+3;
                int t2 = y+3;

                //int z = 0;
                int o = 0;

                while(x<t1){
                    int k = y;
                    if(x<0 || x>=board.size()){
                        x++;
                        continue;
                    }
                    while(k<t2){
                        if(x == i && k == j){
                            k++;
                            continue;
                        }
                        else if(k>=0 && k<board[0].size()){
                            if(board[x][k] == 1) o++;
                        }
                        k++;
                    }

                    x++;
                }

                if(board[i][j] == 0 && o == 3) arr[i].push_back(1);
                else if(board[i][j] == 0) arr[i].push_back(0);
                else if(board[i][j] == 1 && (o<2 || o>3)) arr[i].push_back(0);
                else if(board[i][j] == 1 && (o==2 || o==3)) arr[i].push_back(1);
            }
        }

        board = arr;
    }
};