#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/ */

class Solution {
public:
    char kthCharacter(int k) {
        unordered_map<char,char> m;
        m['z'] = 'a';
        for(int i=0;i<25;i++){
            char c = char(i + 97);
            char n = char(i+1 + 97);
            
            m[c] = n;
        }

        string s = "a";
        while(s.length() < k){
            string temp = s;
            for(char c : s){
                temp.push_back(m[c]);
                if(temp.size() == k) break;
            }
            s = temp;
        }

        return s[k-1];
    }
};