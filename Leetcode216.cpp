#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/combination-sum-iii/ */

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp{1,2,3,4,5,6,7,8,9};
    void find(int k,int n,int sum,int i,vector<int> ref){
        if(sum == n && ref.size() == k){
            ans.push_back(ref);
            return;
        }
        for(int j=i;j<9;j++){
            if((sum+temp[j]) <= n){
                ref.push_back(temp[j]);
                find(k,n,sum+temp[j],j+1,ref);
                ref.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ref;
        find(k,n,0,0,ref);

        return ans;
    }
};