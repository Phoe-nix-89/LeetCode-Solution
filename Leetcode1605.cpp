#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20 */

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        vector<vector<int>> ans(r.size(),vector<int> (c.size(),0));

        while(true){
            int i1 = 0;
            int v1 = INT_MAX;
            int i2 = 0;
            int v2 = INT_MAX;

            for(int i=0;i<r.size();i++){
                if(r[i] != 0 && v1 > r[i]){
                    v1 = r[i];
                    i1 = i;
                }
            }
            for(int i=0;i<c.size();i++){
                if(c[i] != 0 && v2 > c[i]){
                    v2 = c[i];
                    i2 = i;
                }
            }

            int a = min(v1,v2);
            if(a == INT_MAX) break;

            if(v1 != INT_MAX){
                r[i1] = r[i1] - a;
            }
            if(v2 != INT_MAX){
                c[i2] = c[i2] - a;
            }

            ans[i1][i2] = a;
        }

        return ans;
    }
};