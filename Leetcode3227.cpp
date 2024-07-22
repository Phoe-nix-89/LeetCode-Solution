#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/vowels-game-in-a-string/ */

class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
        }

        if(count == 0) return false;
        else if(count == 1) return true;
        else if(count % 2 == 1 || count % 2 == 0) return true;
        return true;
    }
};