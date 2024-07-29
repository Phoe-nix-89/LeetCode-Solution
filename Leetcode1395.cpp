#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29 */

class Solution {
public:
    int numTeams(vector<int>& rating) {

        unordered_map<int,pair<int,int>> m;
        for(int i=0;i<rating.size();i++){
            int c1 = 0,c2 = 0;
            for(int j=i+1;j<rating.size();j++){
                if(rating[j] > rating[i]) c2++;
                else if(rating[j] < rating[i]) c1++;
            }

            m[rating[i]] = {c1,c2};
        }

        int ans = 0;

        for(int i=0;i<rating.size();i++){
            int c1 = 0,c2 = 0;
            for(int j=i+1;j<rating.size();j++){
                if(rating[j] > rating[i]){
                    c2 += m[rating[j]].second;
                }
                else if(rating[j] < rating[i]){
                    c1 += m[rating[j]].first;
                }
            }

            ans += (c1+c2);
        }

        return ans;
    }
};