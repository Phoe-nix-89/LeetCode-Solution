#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1 */

class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
        int temp = n*(n+1)/2;
        for(int x : arr) temp -= x;
        
        return temp;
    }
};