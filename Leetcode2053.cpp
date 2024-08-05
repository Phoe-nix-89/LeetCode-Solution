#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05 */

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        int t = 1;
        for(string s : arr){
            if(m[s] > 1){}
            else{
                if(t == k) return s;
                t++;
            }
        }



        return "";
    }
};