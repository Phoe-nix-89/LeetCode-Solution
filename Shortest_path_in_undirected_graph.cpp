#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1 */

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        unordered_map<int,unordered_set<int>> m;
        for(auto x : edges){
            m[x[0]].insert(x[1]);
            m[x[1]].insert(x[0]);
        }
        
        queue<pair<int,int>> q;
        unordered_set<int> v;
        q.push({src,0});
        v.insert(src);
        
        
        vector<int> ans(N,INT_MAX);
        while(q.size()){
            auto temp = q.front();
            q.pop();
            
            for(int x : m[temp.first]){
                if(v.find(x) == v.end()){
                    q.push({x,temp.second+1});
                    v.insert(x);
                }
                else{
                    if(temp.second+1 < ans[x]) ans[x] = temp.second+1;
                }
            }
            
            ans[temp.first] = min(ans[temp.first],temp.second);
        }
        
        for(int i=0;i<ans.size();i++){
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        
        return ans;
    }
};