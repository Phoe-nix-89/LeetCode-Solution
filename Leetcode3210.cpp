#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-encrypted-string/ */

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string temp = "";
        int t = k%(s.length());
        int i = 0;
        while(i<s.length()){
            temp.push_back(s[t]);
            char c = s[0];
            string r = s.substr(1,s.length());
            r.push_back(c);

            s = r;

            i++;
        }

        return temp;
    }
};