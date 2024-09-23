#include<bits/stdc++.h>
using namespace std;

/**/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_set<int> s;
        long sum1 = arr.size() * (arr.size()+1) / 2;
        long sum2 = 0;
        vector<int> ans;
        for(int x : arr){
            if(s.find(x) == s.end()){
                sum2 += x;
                s.insert(x);
            }
            else{
                ans.push_back(x);
            }
        }
        
        int t = sum1 - sum2;
        ans.push_back(t);
        return ans;
    }
};