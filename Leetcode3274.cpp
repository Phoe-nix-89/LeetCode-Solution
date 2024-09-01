#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/ */

class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int x1 = c1[0] - 'a';
        int x2 = c2[0] - 'a';
        int y1 = c1[1] - '0';
        int y2 = c2[1] - '0';
        if((x1%2 == 0 && x2%2 == 0) || (x1%2 == 1 && x2%2 == 1)){
            if((y1%2 == 0 && y2%2 == 0) || (y1%2 == 1 && y2%2 == 1)) return true;
        }
        else{
            if((y1%2 == 1 && y2%2 == 0) || (y1%2 == 0 && y2%2 == 1)) return true;
        }

        return false;
    }
};