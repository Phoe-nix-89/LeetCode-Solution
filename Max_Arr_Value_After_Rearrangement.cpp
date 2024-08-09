#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1 */

class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        
        long long sum = 0;
        for(int i=0;i<arr.size();i++){
            long long t = (i*(long long)arr[i]);
            sum = (sum + t);
        }
        
        return (int)(sum%1000000007);
    }
};