#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/ */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int elem = -1;
        for(int x : nums){
            elem = max(elem,x);
        }

        int c = 0;
        int ans = 0;
        for(int x : nums){
            if(x == elem) c++;
            else{
                ans = max(ans,c);
                c = 0;
            }
        }
        ans = max(ans,c);
        return ans;
    }
};