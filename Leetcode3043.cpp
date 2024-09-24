#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-24 */

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for(int x : arr1){
            int t = x;
            while(t>0){
                s.insert(t);
                t = t/10;
            }
        }
        int ans = 0;
        for(int x : arr2){
            int t = x;
            while(t>0){
                if(s.find(t) != s.end()){
                    string temp = to_string(t);
                    int r = temp.length();
                    ans = max(ans,r);
                }
                t = t/10;
            }
        }

        return ans;
    }
};