#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/ */

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> m;
        for(char c : word){
            m[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto x : m){
            pq.push({x.second,x.first});
        }

        int i = 1;
        int ans = 0;
        while(pq.size()){
            auto x = pq.top();
            pq.pop();

            if(i>=1 && i<=8){
                ans += x.first;
            }
            else if(i>=9 && i<=16){
                ans += (2*x.first);
            }
            else if(i>=17 && i<=24){
                ans += (3*x.first);
            }
            else{
                ans += (4*x.first);
            }

            i++;
        }

        return ans;
    }
};