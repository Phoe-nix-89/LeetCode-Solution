#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1 */

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int ans = INT_MAX;
        int ind = -1;
        for(int i=0;i<arr.size();i++){
            int s = 0;
            int e = arr[0].size()-1;
            int m = s + (e-s)/2;
            int temp = -1;
            while(s<=e){
                m = s + (e-s)/2;
                if(arr[i][m] == 1){
                    temp = m;
                    e = m-1;
                }
                else if(arr[i][m] == 0){
                    s = m+1;
                }
            }
            
            if(temp != -1){
                if(temp < ans){
                    ans = temp;
                    ind = i;
                }
            }
            
            if(ans  == 0) break;
        }
        
        return ind;
    }
};