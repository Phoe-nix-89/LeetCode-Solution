#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03 */

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        for(int i=0;i<target.size();i++){
            if(target[i] != arr[i]){
                int j = i;
                while(j<target.size() && target[j] != arr[i]){
                    j++;
                }
                if(j==target.size()) return false;

                int t = i;
                while(t<j){
                    swap(target[t],target[j]);
                    t++;
                    j--;
                }
            }
        }

        if(target == arr) return true;
        return false;
    }
};