#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-if-digit-game-can-be-won/ */

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        for(int x : nums){
            if(x < 10) c1 += x;
            else if(x >= 10) c2 += x;
        }

        if(c1>c2 || c2>c1) return true;
        return false;
    }
};