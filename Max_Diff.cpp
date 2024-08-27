#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1 */

class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        vector<int> prev;
        stack<int> st;
        for(int x : arr){
            while(st.size() > 0 && st.top() >= x){
                
                st.pop();
            }
            
            if(st.size() == 0){
                prev.push_back(0);
            }
            else{
                prev.push_back(st.top());
            }
            
            st.push(x);
        }
        
        while(st.size() > 0) st.pop();
        vector<int> next;
        
        for(int i=arr.size()-1;i>=0;i--){
            while(st.size() > 0 && st.top() >= arr[i]){
                
                st.pop();
            }
            
            if(st.size() == 0){
                next.push_back(0);
            }
            else{
                next.push_back(st.top());
            }
            st.push(arr[i]);
        }
        
        reverse(next.begin(),next.end());
        
        int ans = 0;
        
        
        for(int i=0;i<arr.size();i++){
            
            int temp = abs(next[i]-prev[i]);
            ans = max(ans,temp);
        }
        
        
        return ans;
    }
};