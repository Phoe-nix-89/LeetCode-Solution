#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04 */

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,unordered_set<int>> m;
        for(auto x : obstacles){
            m[x[0]].insert(x[1]);
        }

        int x = 0;
        int y = 0;
        char d = 'N';
        int ans = x*x+y*y;
        for(int t : commands){
            if(t == -2){
                if(d == 'N') d = 'W';
                else if(d == 'E') d = 'N';
                else if(d == 'S') d = 'E';
                else if(d == 'W') d = 'S';
            }
            else if(t == -1){
                if(d == 'N') d = 'E';
                else if(d == 'E') d = 'S';
                else if(d == 'S') d = 'W';
                else if(d == 'W') d = 'N';
            }
            else{
                int temp = x*x+y*y;
                ans = max(ans,temp);
                if(d == 'N'){
                    for(int i=1;i<=t;i++){
                        if(m.find(x) == m.end() || m[x].find(y+1) == m[x].end()) y++;
                        else break;
                        temp = x*x+y*y;
                        ans = max(ans,temp);
                    }
                }
                else if(d == 'E'){

                    for(int i=1;i<=t;i++){
                        if(m.find(x+1) == m.end() || m[x+1].find(y) == m[x+1].end()) x++;
                        else break;
                        temp = x*x+y*y;
                        ans = max(ans,temp);
                    }
                }
                else if(d == 'S'){

                    for(int i=1;i<=t;i++){
                        if(m.find(x) == m.end() || m[x].find(y-1) == m[x].end()) y--;
                        else break;
                        temp = x*x+y*y;
                        ans = max(ans,temp);
                    }
                }
                else if(d == 'W'){
                    for(int i=1;i<=t;i++){
                        if(m.find(x-1) == m.end() || m[x-1].find(y) == m[x-1].end()) x--;
                        else break;
                        temp = x*x+y*y;
                        ans = max(ans,temp);
                    }
                }
            }
        }
        return ans;
    }
};