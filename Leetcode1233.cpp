#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2024-10-25 */

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string> s;
        vector<string> ans;
        for(string x : folder){
            
            int j = 0;
            bool temp = true;
            string t = "";
            while(j<x.length()){
                t.push_back(x[j]);
                if(j == (x.length()-1) || x[j+1] == '/' ){
                    if(s.find(t) != s.end()){
                        temp = false;
                        break;
                    }
                }
                j++;
            }

            if(temp){
                ans.push_back(x);
                s.insert(x);
            }
        }

        return ans;
    }
};