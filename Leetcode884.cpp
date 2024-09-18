#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2024-09-17 */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v;
        string temp = "";
        for(char c : s1){
            if(c == ' '){
                v.push_back(temp);
                temp = "";
            }
            else temp.push_back(c);
        }
        if(temp.length() > 0) v.push_back(temp);
        temp = "";
        for(char c : s2){
            if(c == ' '){
                v.push_back(temp);
                temp = "";
            }
            else temp.push_back(c);
        }
        if(temp.length() > 0) v.push_back(temp);

        sort(v.begin(),v.end());
        int c = 1;
        
        vector<string> ans;
        for(int i=1;i<v.size();i++){
            if(v[i] == v[i-1]) c++;
            else{
                if(c == 1) ans.push_back(v[i-1]);
                c = 1;
            }
        }
        if(c == 1) ans.push_back(v[v.size()-1]);
        return ans;
    }
};