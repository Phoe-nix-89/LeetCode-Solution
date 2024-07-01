#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/three-consecutive-odds/description/ */

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c = 0;
        for(int x : arr){
            if(x%2 == 1) c++;
            else{
                if(c >= 3) return true;
                c = 0;
            }
        }

        if(c >= 3) return true;
        return false;
    }
};