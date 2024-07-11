#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2024-07-11 */

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp = "";
        string r = "(";
        for(char c : s){
            if(c == '('){
                if(temp.size() > 0){
                    st.push(temp);
                    temp = "";
                }
                st.push(r);
                
            }
            else if(c == ')'){
                //reverse(temp.begin(),temp.end());
                st.push(temp);
                string k = "";
                while(st.top() != "("){
                    k = st.top() + k;
                    st.pop();
                }
                st.pop();

                reverse(k.begin(),k.end());
                st.push(k);
                temp = "";
            }
            else{
                temp.push_back(c);
            }
        }
        if(temp.size() > 0) st.push(temp);

        string f = "";
        while(st.size()){
            f = st.top() + f;
            st.pop();
        }

        return f;
    }
};