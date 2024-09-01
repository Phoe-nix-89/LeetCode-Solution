#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/k-th-nearest-obstacle-queries/ */

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> q;
        vector<int> ans;
        for(auto x : queries){
            int temp = abs(x[0] - 0) + abs(x[1] - 0);

            q.push(temp);
            if(q.size() < k) ans.push_back(-1);
            else if(q.size() == k){
                ans.push_back(q.top());
            }
            else if(q.size() > k){
                q.pop();
                ans.push_back(q.top());
            }
        }

        return ans;
    }
};