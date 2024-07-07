#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/ */

class Solution {
public:
    vector<string> validStrings(int n) {
        double a = 0;
        double b = pow(2,n);
        string s = "";
        string t = "00";
        vector<string> ans;
        while(a<b){
            int temp = (int)(a);
            while(temp > 0){
                if(temp%2 == 1){
                    s.push_back('1');
                }
                else s.push_back('0');

                temp = temp/2;
            }
            while(s.size() < n){
                s.push_back('0');
            }

            reverse(s.begin(),s.end());

            int i = 0;
            int flag = 1;
            while(i<=(n-2)){
                if(s.substr(i,2) == t){
                    flag = 0;
                    break;
                }
                i++;
            }

            if(flag == 1){
                ans.push_back(s);
            }

            s.clear();
            a += 1.0;
        }

        return ans;
    }
};