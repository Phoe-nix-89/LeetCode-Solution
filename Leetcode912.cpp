#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25 */

class Solution {
public:
    void merge(vector<int> &arr,int l,int m,int r){
        //int s1 = m-l+1;
        //int s2 = r-m;
        vector<int> a;
        vector<int> b;
        for(int i=l;i<=m;i++) a.push_back(arr[i]);
        for(int i=m+1;i<=r;i++) b.push_back(arr[i]);

        int i = 0;
        int j = 0;
        int t = l;
        while(i<a.size() || j<b.size()){
            if(i == a.size()){
                arr[t] = b[j];
                t++;
                j++;
            }
            else if(j == b.size()){
                arr[t] = a[i];
                t++;
                i++;
            }
            else if(a[i] <= b[j]){
                arr[t] = a[i];
                t++;
                i++;
            }
            else if(b[j] < a[i]){
                arr[t] = b[j];
                t++;
                j++;
            }
        }
    }
    void msort(vector<int> &arr,int l,int r){
        if(l == r) return;
        
        int m = l + (r-l)/2;

        msort(arr,l,m);
        msort(arr,m+1,r);

        merge(arr,l,m,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        msort(nums,0,nums.size()-1);

        return nums;
    }
};