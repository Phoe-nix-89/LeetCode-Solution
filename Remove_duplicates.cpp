#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/remove-duplicates3034/1 */

class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        string s = "";
        vector<int> temp(26,0);
        for(char c : str){
            if(temp[c-'a'] == 0){
                s.push_back(c);
                temp[c-'a']++;
            }
        }
        
        return s;
    }
};