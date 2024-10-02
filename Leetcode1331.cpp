#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/rank-transform-of-an-array/submissions/1409536151/?envType=daily-question&envId=2024-10-02 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(int i=0;i<arr.size();i++) p.push({arr[i],i});
        vector<int> ans(arr.size());
        int i = 0;
        int prev = INT_MIN;
        while(p.size()){
            auto t = p.top();
            p.pop();

            if(prev == t.first){
                ans[t.second] = i;
            }
            else{
                i++;
                ans[t.second] = i;
            }

            prev = t.first;
        }

        return ans;
    }
};