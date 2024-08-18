#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1 */

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int sum = 0;
        for(int x : arr){
            sum += x;
        }
        
        if(sum%2 == 1) return false;
        int t = 0;
        for(int i=1;i<arr.size();i++){
            t += arr[i-1];
            sum -= arr[i-1];
            if(t == sum) return true;
        }
        
        return false;
    }
};