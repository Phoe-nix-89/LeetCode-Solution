#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1 */

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    int i = 0;
    int j = m-1;
    long long ans = LLONG_MAX;
    while(j<n){
        long long temp = a[j] - a[i];
        if(temp < ans) ans = temp;
        i++;
        j++;
    }
    return ans;
    
    }   
};