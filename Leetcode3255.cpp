#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/ */

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int c = 1;
        int i = 1;
        int t = 0;
        int r = k-1;
        vector<int> ans;
        while(i<nums.size() && r<nums.size()){
            if(nums[i] == nums[i-1]+1){
                c++;
                i++;
            }
            else{
                if(c >= k){
                    while(t<i && r<nums.size()){
                        if(i>=t && i<=r){
                            ans.push_back(-1);
                        }
                        else ans.push_back(nums[r]);
                        t++;
                        r++;
                    }
                }
                else{
                    while(t<i && r<nums.size()){
                        if(i>=t && i<=r){
                            ans.push_back(-1);
                        }
                        else ans.push_back(nums[r]);
                        t++;
                        r++;
                    }
                }
                i++;
                c = 1;
            }
        }
        if(c>=k){
            while(r<nums.size()){
                ans.push_back(nums[r]);
                t++;
                r++;
            }
        }

        return ans;
    }
};