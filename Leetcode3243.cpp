#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/ */

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<(n-1);i++){
            m[i].insert(i+1);
        }

        queue<pair<int,int>> q;

        vector<int> ans(queries.size(),INT_MAX);
        int i = 0;

        for(auto x : queries){
            m[x[0]].insert(x[1]);
            q.push({0,0});
            unordered_set<int> s;
            s.insert(0);
            //int i = 0;
            while(q.size()){
                int r = q.front().first;
                int l = q.front().second;
                q.pop();
                if(l>=ans[i]) continue;

                if(r == (n-1)){
                    ans[i] = min(ans[i],l);
                }

                for(int t : m[r]){
                    if(s.find(t) == s.end() && (l+1) < ans[i]){
                        s.insert(r);
                        q.push({t,l+1});
                    }
                }
            }
            i++;
        }

        return ans;
    }
};