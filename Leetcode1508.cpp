#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04 */

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pre;
        int s = 0;
        for(int x : nums){
            s += x;
            pre.push_back(s);
        }

        int i = -1;
        vector<int> temp;
        while(i<(n-1)){
            int j = i+1;
            while(j<n){
                if(i < 0){
                    temp.push_back(pre[j]);
                }
                else {
                    temp.push_back((pre[j] - pre[i]));
                }
                j++; 
            }
            i++;
        }

        sort(temp.begin(),temp.end());
        i = left-1;
        int j = right-1;
        s = 0;
        while(i<=j){
            s = (s+temp[i])%1000000007;
            i++;
        }

        return s;
    }
};