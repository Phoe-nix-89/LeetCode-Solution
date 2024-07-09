#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09 */

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        double t = 0;
        for(auto x : customers){
            if(ans == 0){
                ans += (x[1]);
                t += (x[1]+x[0]);
            }
            else{
                ans += (x[1]);
                if(t > x[0]){
                    ans += (t - x[0]);
                    t += x[1];
                }
                else{
                    t = x[0];
                    t += (x[1]);
                }
            }
        }

        return (ans/customers.size());
    }
};