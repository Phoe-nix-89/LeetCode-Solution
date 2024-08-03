#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/the-celebrity-problem/1 */

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        vector<int> temp(mat.size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i != j && mat[i][j] == 1){
                    
                    temp[i] = -1;
                    if(temp[j] != -1) temp[j]++;
                }
            }
        }
        
        for(int i=0;i<temp.size();i++){
            if(temp[i] == (temp.size()-1)) return i;
        }
        
        return -1;
    }
};