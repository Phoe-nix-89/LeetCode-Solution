#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/count-almost-equal-pairs-i/ */

class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c = 0;
        for(int i=0;i<nums.size();i++){
            string r = to_string(nums[i]);
            string s = r;
            int t1 = stoi(r);
            for(int j=i+1;j<nums.size();j++){
                string e = to_string(nums[j]);
                if(s == e) c++;
                else{
                    bool f = false;
                    for(int k=0;k<e.length();k++){
                        for(int l=k+1;l<e.length();l++){
                            string t = e;
                            char a = t[k];
                            char b = t[l];
                            t[l] = a;
                            t[k] = b;

                            int temp = stoi(t);
                            if(temp == t1){
                                f = true;
                            }

                            if(f == true) break;
                        }
                        if(f == true) break;
                    }

                    if(f == true) c++;
                }
            }
        }

        return c;
    }
};