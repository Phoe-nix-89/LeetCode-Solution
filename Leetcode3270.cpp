#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-key-of-the-numbers/ */

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);
        while(s1.length() < 4){
            s1 = "0"+s1;
        }
        while(s2.length() < 4){
            s2 = "0"+s2;
        }
        while(s3.length() < 4){
            s3 = "0"+s3;
        }

        int ans = 0;
        for(int i=0;i<s1.length();i++){
            int n1 = s1[i] - '0';
            int n2 = s2[i] - '0';
            int n3 = s3[i] - '0';

            int n = min(n1,min(n2,n3));
            ans = ans*10+n;
        }

        return ans;
    }
};