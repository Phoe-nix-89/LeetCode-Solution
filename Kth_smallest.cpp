#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1 */

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int m = 1;
        for(int x : arr) m = max(x,m);
        vector<int> temp(m+1,0);
        for(int x : arr) temp[x]++;
        
        int i = 1;
        for(int j=0;j<m+1;j++){
            if(temp[j] == 1 && i == k) return j;
            else if(temp[j] == 1) i++;
        }
        
        return 0;
    }
};