#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1 */

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int mini = 0;
        int maxi = matrix.size()-1;
        int minj = 0;
        int maxj = matrix[0].size()-1;
        vector<int> ans;
        while(mini<=maxi && minj<=maxj){
            int i = mini;
            int j = minj;
            while(j<=maxj){
                ans.push_back(matrix[i][j]);
                j++;
            }
            mini++;
            if(mini>maxi || minj>maxj){
                break;
            }
            
            
            i = mini;
            j = maxj;
            while(i<=maxi){
                ans.push_back(matrix[i][j]);
                i++;
            }
            maxj--;
            if(mini>maxi || minj>maxj){
                break;
            }
            
            i = maxi;
            j = maxj;
            while(j>=minj){
                ans.push_back(matrix[i][j]);
                j--;
            }
            maxi--;
            if(mini>maxi || minj>maxj){
                break;
            }
            
            i = maxi;
            j = minj;
            while(i>=mini){
                ans.push_back(matrix[i][j]);
                i--;
            }
            minj++;
            if(mini>maxi || minj>maxj){
                break;
            }
            
        }
        
        return ans;
    }
};