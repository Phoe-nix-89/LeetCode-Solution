#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1 */

class Solution {
  public:
    int isValid(string str) {
        // code here
        string s = "";
        int c = 0;
        for(auto x : str){
            if(x == '.'){
                if(s.length() > 0){
                    int n = stoi(s);
                    if(n<0 || n>255) return 0;
                    s = "";
                }
                else return 0;
                c++;
            }
            else{
                s.push_back(x);
            }
        }
        
        if(s.length() > 0){
            int n = stoi(s);
            if(n<0 || n>255) return 0;
            s = "";
        }
        c++;
        
        if(c > 4 || c < 4) return 0;
        return 1;
    }
};