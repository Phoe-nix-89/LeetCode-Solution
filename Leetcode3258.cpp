#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/ */

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int z = 0;
            int o = 0;
            for(int j=i;j<s.length();j++){
                if(s[j] == '0') z++;
                else o++;

                if(z<=k || o<=k) ans++;
                else break;
            }
        }

        return ans;
    }
};