#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/hash-divided-string/ */

class Solution {
public:
    string stringHash(string s, int k) {
        int i = 0;
        int j = k-1;
        string ans = "";
        while(j<s.length()){
            int sum = 0;
            for(int m=i;m<=j;m++){
                sum += (s[m] - 'a');
            }

            int r = sum%26;
            char c = 97 + r;
            ans.push_back(c);
            i+=k;
            j+=k;
        }

        return ans;
    }
};