#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30 */

class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> b;
        //vector<int> a(s.length(),0);
        int c = 0;
        for(char t : s){
            if(t == 'b') c++;
            b.push_back(c);
        }
        c = 0;
        int ans = INT_MAX;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == 'a') c++;

            int t1 = 0;
            int t2 = 0;
            if(i-1>=0) t1 = b[i-1];
            if(i+1<s.size()) t2 = c;

            ans = min(ans,(t1+t2));
        }

        return ans;
    }
};