#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1 */

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long neg = 0;
        long long pos = 0;
        long long zero = 0;
        sort(arr.begin(),arr.end());
        for(int x : arr){
            if(x > 0) pos++;
            if(x == 0) zero++;
            if(x < 0) neg++;
        }
        
        if(neg == 0){
            if(pos == 0 && zero > 0) return 0;
            else if(pos > 0){
                long long ans = 1;
                for(int x : arr){
                   if(x > 0)  ans = ((ans*x)%1000000007);
                }
                
                return ans;
            }
        }
        else if(neg == 1){
            if(pos == 0 && zero > 0) return 0;
            else if(pos > 0){
                long long ans = 1;
                for(int x : arr){
                    if(x > 0) ans = ((ans*x)%1000000007);
                }
                
                return ans;
            }
            else if(pos == 0 && zero == 0){
                return arr[0];
            }
        }
        else if(neg > 1){
            if(pos > 0){
                int idx;
                if(neg%2 == 0){
                    idx = neg-1;
                }
                else if(neg%2 == 1){
                    idx = neg-1-1;
                }
                long long a1 = 1;
                long long a2 = 1;
                for(int i=0;i<arr.size();i++){
                    if(i<=idx){
                        a1 = ((a1*arr[i])%1000000007);
                    }
                    else if(i>idx && arr[i]>0){
                        a2 = ((a2*arr[i])%1000000007);
                    }
                }
                
                long long ans = (a1*a2)%1000000007;
                return ans;
            }
            else if(pos == 0 || zero == 0){
                int idx;
                if(neg%2 == 0){
                    idx = neg-1;
                }
                else if(neg%2 == 1){
                    idx = neg-1-1;
                }
                long long a1 = 1;
                
                for(int i=0;i<arr.size();i++){
                    if(i<=idx){
                        a1 = ((a1*arr[i])%1000000007);
                    }
                }
                return a1;
            }
        }
        
        return 0;
    }
};