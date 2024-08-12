#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1 */

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size() + arr2.size();
        if(n % 2 == 1){
            int i = 0;
            int j = 0;
            int k = 0;
            while(i<arr1.size() || j<arr2.size()){
                
                
                if(i == arr1.size()){
                    if(k == (n/2)) return arr2[j];
                    j++;
                }
                else if(j == arr2.size()){
                    if(k == (n/2)) return arr1[i];
                    i++;
                }
                else if(arr1[i] <= arr2[j]){
                    if(k == (n/2)) return arr1[i];
                    i++;
                }
                else if(arr2[j] < arr1[i]){
                    if(k == (n/2)) return arr2[j];
                    j++;
                }
                
                k++;
            }
        }
        
        int i = 0;
        int j = 0;
        int k = 0;
        int ans = 0;
        while(i<arr1.size() || j<arr2.size()){
                
                
            if(i == arr1.size()){
                if(k == (n/2) || k == (n/2 - 1)) ans += arr2[j];
                j++;
            }
            else if(j == arr2.size()){
                if(k == (n/2) || k == (n/2 - 1)) ans += arr1[i];
                i++;
            }
            else if(arr1[i] <= arr2[j]){
                if(k == (n/2) || k == (n/2 - 1)) ans += arr1[i];
                i++;
            }
            else if(arr2[j] < arr1[i]){
                if(k == (n/2) || k == (n/2 - 1)) ans += arr2[j];
                j++;
            }
            
            if(k == (n/2)) break;
                
            k++;
        }
        
        return ans;
    }
};