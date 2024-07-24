#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24 */

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> temp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(int i=0;i<nums.size();i++){
            string x = "" + to_string(nums[i]);
            for(int j=0;j<x.length();j++){
                x[j] = char(mapping[x[j] - '0'] + 48);
            }

            int t = stoi(x);

            p.push({t,i});
        }
        vector<int> v;

        while(p.size()){
            v.push_back(nums[p.top().second]);
            p.pop();
        }

        return v;
    }
};