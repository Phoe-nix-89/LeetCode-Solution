#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/2-keys-keyboard/?envType=daily-question&envId=2024-08-19 */

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int c = 0;
        int last = 1;
        int k = 1;
        while(k<n){
            if(n%k == 0){
                c++;
                last = k;
                c++;
                k += last;
            }
            else{
                c++;
                k += last;
            }
        }

        return c;
    }
};