#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1 */

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(char c : x){
            if((c == '}' || c == ']' || c == ')')){
                if(st.size() == 0) return false;
                else if(c == ']' && st.top() == '[') st.pop();
                else if(c == ')' && st.top() == '(') st.pop();
                else if(c == '}' && st.top() == '{') st.pop();
                else return false;
            }
            else if(c == '[' || c == '{' || c == '(') st.push(c);
        }
        
        if(st.size() > 0) return false;
        return true;
    }

};