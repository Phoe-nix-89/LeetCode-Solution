#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03 */

class Solution {
public:
    int getLucky(string s, int k) {
        int temp = 0;
        for(char c : s){
            int t = c - 'a' + 1;
            if(t < 10) temp += t;
            else{
                temp += t%10;
                t = t/10;
                temp += t%10;
            }
        }
        //cout<<temp<<endl;

        k--;
        while(k>0 && temp>=10){
            //cout<<temp<<endl;
            int t = temp;
            int ans = 0;
            while(t>0){
                ans += (t%10);
                t = t/10;
            }
            temp = ans;
            k--;
        }

        return temp;
    }
};