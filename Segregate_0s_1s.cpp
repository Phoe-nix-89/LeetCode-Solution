#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1 */

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            if(arr[i] == 0 && arr[j] == 0){
                i++;
            }
            else if(arr[i] == 0 && arr[j] == 1){
                i++;
                j--;
            }
            else if(arr[i] == 1 && arr[j] == 0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else{
                j--;
            }
        }
    }
};