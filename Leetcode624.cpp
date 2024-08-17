#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16 */

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<vector<int>> sm;
        vector<vector<int>> bg;
        for(int i=0;i<arrays.size();i++){
            sm.push_back({arrays[i][0],i});
            bg.push_back({arrays[i][arrays[i].size()-1],i});
        }

        sort(sm.begin(),sm.end());
        sort(bg.begin(),bg.end());

        int m = 0;
        for(int i=0;i<bg.size();i++){
           int t = -1;
           if(sm[i][1] != bg[0][1]){
            t = abs(sm[i][0] - bg[0][0]);
           }
           else if(1<bg.size()){
            t = abs(sm[i][0] - bg[1][0]);
           }
           m = max(t,m);
           t = -1;

           if(sm[i][1] != bg[bg.size()-1][1]){
            t = abs(sm[i][0] - bg[bg.size()-1][0]);
           }
           else if(bg.size()-2>=0){
            t = abs(sm[i][0] - bg[bg.size()-2][0]);
           }
           m = max(t,m);
           t = -1;

           if(bg[i][1] != sm[0][1]){
            t = abs(bg[i][0] - sm[0][0]);
           }
           else if(1<bg.size()){
            t = abs(bg[i][0] - sm[1][0]);
           }
           m = max(t,m);
           t = -1;

           if(bg[i][1] != sm[sm.size()-1][1]){
            t = abs(bg[i][0] - sm[sm.size()-1][0]);
           }
           else if(sm.size()-2>=0){
            t = abs(bg[i][0] - sm[sm.size()-2][0]);
           }
           m = max(t,m);
        }

        return m;
    }
};