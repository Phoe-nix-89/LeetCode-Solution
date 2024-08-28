#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1 */

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> m;
        for(int x : arr) m[x]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto x : m){
            int t = (-1)*x.first;
            pq.push({x.second,t});
        }
        
        vector<int> ans;
        
        while(pq.size()){
            for(int i=0;i<pq.top().first;i++){
                ans.push_back(((-1)*pq.top().second));
            }
            
            pq.pop();
        }
        
        return ans;
    }
};