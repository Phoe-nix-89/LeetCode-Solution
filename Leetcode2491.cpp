#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-10-04 */

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;
        unordered_map<int,int> h;
        for(int x : skill){
            sum += x;
            h[x]++;
        }

        int n = skill.size()/2;
        if(sum % n != 0) return -1;
        int temp = sum/n;
        long long s = 0;
        bool f = true;

        for(int x : skill){
            int t = x;
            
            if(h[t] == 0) continue;
            h[t]--;
            
            int r = temp - t;
            
            if(h.find(r) == h.end() || h[r] == 0){
                f = false;
                break;
            }

            h[r]--;
            
            s += (t*r);
            

        }
        if(f == false) return -1;
        
        

        return s;
    }
};