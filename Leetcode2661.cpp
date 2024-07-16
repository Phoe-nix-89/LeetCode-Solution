#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/first-completely-painted-row-or-column/ */

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[mat[i][j]] = {i,j};
            }
        }

        unordered_map<int,int> r;
        unordered_map<int,int> c;

        for(int i=0;i<arr.size();i++){
            int x = m[arr[i]].first;
            int y = m[arr[i]].second;

            r[x]++;
            c[y]++;

            if(r[x] == mat[0].size() || c[y] == mat.size()) return i;
        }

        return -1;
    }
};