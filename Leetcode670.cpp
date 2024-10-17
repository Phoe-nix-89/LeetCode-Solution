#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/maximum-swap/?envType=daily-question&envId=2024-10-17 */

class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int ans = 0;
        ans = max(ans,num);
        int i = 0;
        int j = 1;
        while(j<temp.length()){

            for(int k=j;k<temp.length();k++){
                string t = temp;
                swap(t[i],t[k]);

                int r = stoi(t);
                ans = max(ans,r);
            }

            i++;
            j++;
        }

        return ans;
    }
};