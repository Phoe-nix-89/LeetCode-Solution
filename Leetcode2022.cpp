#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01 */

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if((m*n) > original.size()) return {};
        vector<vector<int>> v(m,vector<int> (n));
        int k = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i][j] = original[k];
                k++;
            }
        }

        if(k<original.size()) return {};

        return v;
    }
};