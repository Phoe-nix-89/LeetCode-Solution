
/* https://leetcode.com/problems/maximum-total-importance-of-roads/description/*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> m;
        
        for(auto x : roads){
            m[x[0]]++;
            m[x[1]]++;
        }
        priority_queue<long long , vector<long long> , greater<long long>> pq;

        for(auto x : m){
            pq.push(x.second);
        }
        while(pq.size() != n){
            pq.push(0);
        }

        long long ans = 0;

        for(int i=1;i<=n;i++){
            ans += (i * pq.top());
            pq.pop();
        }

        return ans;
    }
};