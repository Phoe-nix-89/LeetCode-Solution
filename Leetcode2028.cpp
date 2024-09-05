#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05 */

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int temp = 0;
        for(int x : rolls) temp += x;

        int d = (n+rolls.size())*mean;
        temp = d - temp;
        double k = ((double)(temp*1.0)) / ((double)(n*1.0));
        cout<<k;
        if(k>6 || k<1) return {};

        int t = (int)(k);
        cout<<t;
        if(t*1.0 == k){
            vector<int> v;
            while(temp > 0){
                //cout<<t;
                v.push_back(t);
                temp -= t;
            }

            return v;
        }
        vector<int> v;
        //v.push_back(t+1);
        //temp -= (t+1);
        while(temp > 0){
            int r = temp/n;
            v.push_back(r);
            temp -= r;
            n--;
        }

        return v;
    }
};