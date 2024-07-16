#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/remaining-string3515/1 */

class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        for(int i=0;i<s.length();i++){
            if(s[i] == ch){
                count--;
            }
            
            if(count == 0){
                if(i == (s.length()-1)) return "";
                else return s.substr(i+1,s.length());
            }
        }
        
        return "";
    }
};