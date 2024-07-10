#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/crawler-log-folder/?envType=daily-question&envId=2024-07-10 */

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string x : logs){
            if(x == "../"){
                if(st.size() > 0) st.pop();
            }
            else if(x == "./"){
            }
            else{
                st.push(x);
            }
        }

        return st.size();
    }
};