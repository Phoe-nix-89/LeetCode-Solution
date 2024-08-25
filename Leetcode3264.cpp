#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/ */

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k>0){
            int m = nums[0];
            int ind = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] < m){
                    m = nums[i];
                    ind = i;
                }
            }

            nums[ind] = nums[ind]*multiplier;
            k--;
        }

        return nums;
    }
};