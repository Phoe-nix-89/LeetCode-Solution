/*https://leetcode.com/problems/find-center-of-star-graph/description/*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;

        for(vector<int> x : edges){
            m[x[0]]++;
            m[x[1]]++;

            if(m[x[0]] > 1) return x[0];
            else if(m[x[1]] > 1) return x[1];
        }

        return -1;
    }
};