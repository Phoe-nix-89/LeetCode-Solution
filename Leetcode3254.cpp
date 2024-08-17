#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/ */

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0;
        int j = k-1;
        while(j<nums.size()){
            int m = 0;
            int f = true;
            m = max(m,nums[i]);
            for(int r = i+1;r<=j;r++){
                if(nums[r] != nums[r-1]+1){
                    f = false;
                    break;
                }
                m=max(m,nums[r]);
            }

            if(f) ans.push_back(m);
            else ans.push_back(-1);
            i++;
            j++;
        }

        return ans;
    }
};