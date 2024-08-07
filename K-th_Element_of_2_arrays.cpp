#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1 */

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i = 0;
        int j = 0;
        int t = 1;
        while(i<arr1.size() || j<arr2.size()){
            if(t == k) {
                if(i<arr1.size() && j<arr2.size()) return min(arr1[i],arr2[j]);
                else if(i<arr1.size()) return arr1[i];
                else if(j<arr2.size()) return arr2[j];
            }
            
            if(i == arr1.size()) j++;
            else if(j == arr2.size()) i++;
            else if(arr1[i] <= arr2[j]) i++;
            else if(arr1[i] > arr2[j]) j++;
            
            t++;
        }
        
        return -1;
    }
};