#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-complement/?envType=daily-question&envId=2024-08-22 */

class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;
        long long n1 = 1;
        long long n2 = 2;
        long long ans = 0;
        while(true){
            if(num>n2 || (num>=n1 && num<=n2)){
                ans += n1;
            }
            else break;

            n1 = n1*2;
            n2 = n2*2;
        }

        return (ans ^ num);
    }
};