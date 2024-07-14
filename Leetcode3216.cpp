#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/ */

class Solution {
public:
    string getSmallestString(string s) {
        int i = 0;
        int j = 1;
        while(j<s.length()){
            int n1 = s[i] - '0';
            int n2 = s[j] - '0';
            if(((n1%2 == 1 && n2%2 == 1) || (n1%2 == 0 && n2%2 == 0)) && n2<n1  ){
                swap(s[i],s[j]);
                break;
            }
            i++;
            j++;
        }

        return s;
    }
};