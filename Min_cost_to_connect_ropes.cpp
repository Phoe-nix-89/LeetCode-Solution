#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1 */

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto x : arr){
            pq.push(x);
        }
        long long ans = 0;
        if(pq.size() == 1) return 0;
        
        while(pq.size() > 1){
            long long temp = 0;
            temp += pq.top();
            pq.pop();
            if(pq.size() > 0){
                temp += pq.top();
                pq.pop();
            }
            
            ans += temp;
            
            pq.push(temp);
        }
        
        return ans;
    }
};