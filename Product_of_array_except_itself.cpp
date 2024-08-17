#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1 */

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int p = 1;
        int c = 0;
        long long int temp = 1;
        for(long long int x : nums){
            p = p * x;
            if(x == 0) c++;
            
            if(x != 0) temp = temp * x;
        }
        
        vector<long long int> ans;
        for(long long int x : nums){
            if(x == 0){
                c = c-1;
                if(c > 0) ans.push_back(0);
                else{
                    ans.push_back(temp);
                }
                
                c = c+1;
            }
            else{
                if(c > 0) ans.push_back(0);
                else{
                    long long t = p/x;
                    ans.push_back(t);
                }
            }
        }
        
        return ans;
    }
};