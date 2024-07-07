#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/range-sum-query-2d-immutable/ */

class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        v.resize(matrix.size(),vector<int> ());
        for(int i=0;i<matrix.size();i++){
            int sum = 0;
            for(int j=0;j<matrix[0].size();j++){
                sum += matrix[i][j];
                v[i].push_back(sum);
                cout<<sum<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        if(col1 == 0){
            int sum = 0;
            for(int i=row1;i<=row2;i++){
                sum += v[i][col2];
            }

            return sum;
        }
        int sum = 0;
        for(int i=row1;i<=row2;i++){
            sum += (v[i][col2] - v[i][col1-1]);
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */