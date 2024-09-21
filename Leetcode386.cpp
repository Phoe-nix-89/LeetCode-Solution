#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21 */

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string,vector<string>,greater<string>> p;
        for(int i=1;i<=n;i++){
            string temp = "" + to_string(i);
            p.push(temp);
        }
        vector<int> v;
        while(p.size() > 0){
            int temp = stoi(p.top());
            p.pop();
            v.push_back(temp);
        }

        return v;
    }
};