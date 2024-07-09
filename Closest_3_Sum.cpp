#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/three-sum-closest/1 */

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int i = 0;
        int ans = INT_MAX;
        int diff = INT_MAX;
        while(i<=(arr.size()-3)){
            int temp = target - arr[i];
            int j = i+1;
            int k = arr.size()-1;
            while(j<k){
                if((arr[j]+arr[k]) == temp) return target;
                else{
                    int t = abs(target - (arr[i]+arr[j]+arr[k]));
                    if(t<diff){
                        ans = arr[i]+arr[j]+arr[k];
                        diff = t;
                    }
                    else if(t == diff && (arr[i]+arr[j]+arr[k]) > ans){
                        ans = arr[i]+arr[j]+arr[k];
                        diff = t;
                    }
                }
                
                if(arr[j]+arr[k] > temp) k--;
                else if(arr[j]+arr[k] < temp) j++;
            }
            
            i++;
        }
        
        return ans;
    }
};