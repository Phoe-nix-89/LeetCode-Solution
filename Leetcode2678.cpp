#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-of-senior-citizens/?envType=daily-question&envId=2024-08-01 */

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c = 0;
        for(string x : details){
            string temp = "" + x.substr(11,2);
            int t = stoi(temp);
            if(t > 60) c++;
        }

        return c;
    }
};