#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1 */

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string temp = arr[0];
        for(string x : arr){
            if(x.length() < temp.length()) temp = x;
        }
        
        int i = 0;
        
        while(i<temp.length()){
            bool flag = true;
            for(int j=0;j<arr.size();j++){
                if(temp[i]!=arr[j][i]){
                    flag = false;
                    break;
                }
            }
            
            if(flag == false) break;
            
            i++;
        }
        
        
        if(i == 0) return "-1";
        return temp.substr(0,i);
    }
};