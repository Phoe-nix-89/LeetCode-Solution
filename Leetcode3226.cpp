#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/ */

class Solution {
public:
    int minChanges(int n, int k) {
        if(n == k) return 0;
        string b1 = "";
        string b2 = "";
        while(n>0){
            int t = n%2;
            
            b1 = to_string(t) + b1;

            n = n/2;
        }
        while(k>0){
            int t = k%2;

            b2 = to_string(t) + b2;

            k = k/2;
        }

        while(b1.size() < b2.size()){
            b1 = "0" + b1;
        }
        while(b2.size() < b1.size()){
            b2 = "0" + b2;
        }

        int c = 0;

        for(int i=0;i<b1.size();i++){
            if(b1[i] == '1' && b2[i] == '0'){
                b1[i] = '0';
                c++;
            }
        }

        if(b1 == b2) return c;
        return -1;
    }
};