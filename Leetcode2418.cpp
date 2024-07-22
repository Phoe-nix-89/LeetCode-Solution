#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/sort-the-people/?envType=daily-question&envId=2024-07-22 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> m;
        for(int i=0;i<names.size();i++){
            m[heights[i]] = names[i];
        }

        sort(heights.begin(),heights.end());
        vector<string> v;
        for(int i=heights.size()-1;i>=0;i--){
            v.push_back(m[heights[i]]);
        }

        return v;
    }
};