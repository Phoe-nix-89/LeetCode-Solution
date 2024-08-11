#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/snake-in-matrix/ */

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& comm) {
        int i = 0;
        int j = 0;
        for(auto x : comm){
            if(x == "RIGHT"){
                j++;
            }
            else if(x == "LEFT") j--;
            else if(x == "UP") i--;
            else if( x == "DOWN") i++;
        }

        return (i*n+j);
    }
};