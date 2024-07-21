#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-winning-player-in-coin-game/ */

class Solution {
public:
    string losingPlayer(int x, int y) {
        string ans = "Bob";
        while(true){
            if(x>=1 && y>=4){
                x -= 1;
                y -= 4;
                if(ans == "Alice") ans = "Bob";
                else ans = "Alice";
            }
            else break;
        }

        return ans;
    }
};