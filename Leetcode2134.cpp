#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/?envType=daily-question&envId=2024-08-02 */

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0;
        for(int x : nums) k+=x;
        if(k == nums.size()) return 0;
        
        int i = 0;
        int n = k-1;
        int mx = 0;
        int ans = 0;
        for(int j=i;j<=n;j++) mx += nums[j];
        ans = max(ans,mx);
        
        i++;
        n++;
        
        while(n<nums.size() && i<nums.size()){
            if(nums[i-1] == 1) mx--;
            if(nums[n] == 1) mx++;

            ans = max(ans,mx);

            i++;
            n++;

            if(n == nums.size()) n = 0;
        }

        return (k-ans);
    }
};