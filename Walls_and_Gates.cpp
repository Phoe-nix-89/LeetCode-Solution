#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> v;
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int t) {
    // Write your code here.
   
    v = a;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
          if(a[i][j] == 0){
              q.push({{i,j},0});
          }
        }
    }
    unordered_map<int,unordered_set<int>> m;

    while(q.size()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int l = q.front().second;
        if(a[x][y] == INT_MAX){
            v[x][y] = l;
        }
        q.pop();

        if(x-1>=0 && a[x-1][y] == INT_MAX ){
            if(m.find(x-1) != m.end() && m[x-1].find(y) != m[x-1].end()){
                if(v[x-1][y] > l+1){
                    v[x-1][y] = l+1;
                }
            }
            else{
                m[x-1].insert(y);
                q.push({{x-1,y},l+1});
            }
        }
        if(x+1<a.size() && a[x+1][y] == INT_MAX ){
            if(m.find(x+1) != m.end() && m[x+1].find(y) != m[x+1].end()){
                if(v[x+1][y] > l+1){
                    v[x+1][y] = l+1;
                }
            }
            else{
                m[x+1].insert(y);
                q.push({{x+1,y},l+1});
            }
        }
        if(y-1>=0 && a[x][y-1] == INT_MAX ){
            if(m.find(x) != m.end() && m[x].find(y-1) != m[x].end()){
                if(v[x][y-1] > l+1){
                    v[x][y-1] = l+1;
                }
            }
            else{
                m[x].insert(y-1);
                q.push({{x,y-1},l+1});
            }
        }
        if(y+1<a[0].size() && a[x][y+1] == INT_MAX ){
            if(m.find(x) != m.end() && m[x].find(y+1) != m[x].end()){
                if(v[x][y+1] > l+1){
                    v[x][y+1] = l+1;
                }
            }
            else{
                m[x].insert(y+1);
                q.push({{x,y+1},l+1});
            }
        }
    }

    return v;
}