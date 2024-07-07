#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06 */

class Solution {
public:
    int passThePillow(int n, int time) {
        int times = time/(n-1);
        int r = time%(n-1);

        if(times % 2 == 1){
            return (n-r);
        }
        return (1+r);
    }
};