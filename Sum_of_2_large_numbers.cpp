#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1 */

class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int i = X.length()-1;
        int j = Y.length()-1;
        int c = 0;
        string ans = "";
        while(i>=0 || j>=0){
            if(i < 0){
                int temp = (Y[j]-'0') + c;
                int r = temp%10;
                char ch = r + 48;
                if(temp >= 10){
                    c = 1;
                }
                else c = 0;
                ans.push_back(ch);
                
                j--;
            }
            else if(j<0){
                int temp = (X[i]-'0') + c;
                int r = temp%10;
                char ch = r + 48;
                if(temp >= 10){
                    c = 1;
                }
                else c = 0;
                ans.push_back(ch);
                
                i--;
            }
            else{
                int temp = (X[i]-'0') + (Y[j]-'0') + c;
                int r = temp%10;
                char ch = r + 48;
                if(temp >= 10){
                    c = 1;
                }
                else c = 0;
                ans.push_back(ch);
                
                i--;
                j--;
            }
        }
        
        if(c==1){
            ans.push_back('1');
        }
        
        string s = "";
        i = ans.length()-1;
        
        while(ans[i] == '0'){
            i--;
        }
        
        if(i<0) return "0";
        while(i>=0){
            s.push_back(ans[i]);
            i--;
        }
        return s;
    }
};