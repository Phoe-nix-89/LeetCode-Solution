#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/ */

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        
        unordered_set<char> s;
        int ans =0 ;
        for(int i=0;i<word.length();i++){
            int c = 0, v = 0;
            for(int j=i;j<word.length();j++){
                if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u'){
                    s.insert(word[j]);
                }
                else{
                    c++;
                }

                if(c == k && s.size() == 5) ans++;
            }

            s.clear();
        }

        return ans;
    }
};