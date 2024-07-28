#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/as-far-from-land-as-possible/ */

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    m[i].insert(j);
                }
            }
        }

        if(q.size() == 0) return -1;
        
        vector<vector<int>> v(grid.size(),vector<int> (grid[0].size(),INT_MAX));

        int ans = 0;

        while(q.size()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int l = q.front().second;
            q.pop();

            if(grid[x][y] == 0){
                ans = max(ans,v[x][y]);
            }

            if(x-1>=0 && grid[x-1][y] == 0){
                if(m.find(x-1) != m.end() && m[x-1].find(y) != m[x-1].end()){
                    int t = min(v[x-1][y],l+1);
                    ans = max(ans,t);
                    v[x-1][y] = t;
                }
                else{
                    q.push({{x-1,y},l+1});
                    v[x-1][y] = l+1;
                    m[x-1].insert(y);
                }
            }
            if(x+1<grid.size() && grid[x+1][y] == 0){
                if(m.find(x+1) != m.end() && m[x+1].find(y) != m[x+1].end()){
                    int t = min(v[x+1][y],l+1);
                    ans = max(ans,t);
                    v[x+1][y] = t;
                }
                else{
                    q.push({{x+1,y},l+1});
                    v[x+1][y] = l+1;
                    m[x+1].insert(y);
                }
            }
            if(y-1>=0 && grid[x][y-1] == 0){
                if(m.find(x) != m.end() && m[x].find(y-1) != m[x].end()){
                    int t = min(v[x][y-1],l+1);
                    ans = max(ans,t);
                    v[x][y-1] = t;
                }
                else{
                    q.push({{x,y-1},l+1});
                    v[x][y-1] = l+1;
                    m[x].insert(y-1);
                }
            }
            if(y+1<grid[0].size() && grid[x][y+1] == 0){
                if(m.find(x) != m.end() && m[x].find(y+1) != m[x].end()){
                    int t = min(v[x][y+1],l+1);
                    ans = max(ans,t);
                    v[x][y+1] = t;
                }
                else{
                    q.push({{x,y+1},l+1});
                    v[x][y+1] = l+1;
                    m[x].insert(y+1);
                }
            }
        }

        if(ans == 0) return -1;
        return ans;
    }
};