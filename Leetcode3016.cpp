#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/ */

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> s(26,0);
        for(char c : word){
            s[c-'a']++;
        }

        int n = s.size();
        if(n<=8) return word.length();

        sort(s.begin(),s.end());

        int i = 1;
        int c = 1;
        int ans = 0;
        int j = s.size()-1;
        while(j>=0){
            if(s[j] == 0){
                break;
            }

            
            if(c<=8){
                i=1;
            }
            else if(c>=9 && c<=16){
                i=2;
            }
            else if(c>=17 && c<=24){
                i=3;
            }
            else{
                i=4;
            }

            ans += (i*s[j]);

            c++;
            j--;
        }

        return ans;
    }
};