#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16 */

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        string ans = "";
        while(pq.size() > 0){
            if(ans.size() < 2){
                auto temp = pq.top();
                pq.pop();
                ans.push_back(temp.second);
                if(temp.first - 1 != 0) pq.push({temp.first - 1,temp.second});
            }
            else{
                auto temp = pq.top();
                pq.pop();
                if(ans[ans.length()-1] == temp.second && ans[ans.length()-2] == temp.second){
                    if(pq.size() == 0) break;
                    else{
                        auto t = pq.top();
                        pq.pop();
                        ans.push_back(t.second);
                        if(t.first - 1 != 0) pq.push({t.first - 1,t.second});
                    }
                }
                
                ans.push_back(temp.second);
                if(temp.first - 1 != 0) pq.push({temp.first - 1,temp.second});
            }
        }

        return ans;
    }
};