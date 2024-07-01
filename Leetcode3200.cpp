#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/contest/weekly-contest-404/problems/maximum-height-of-a-triangle/description/ */

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int m1 = 0;
        int i = 1;
        int r = red;
        int b = blue;
        while(red>0 || blue>0){
            if(i % 2 == 1){
                if(red < i) break;
                red -= i;
            }
            else{
                if(blue < i) break;
                blue -= i;
            }

            m1 = max(m1,i);
            i++;
        }

        int m2 = 0;
        i = 1;
        while(r>0 || b>0){
            if(i % 2 == 1){
                if(b < i) break;
                b -= i;
            }
            else{
                if(r < i) break;
                r -= i;
            }
            

            m2 = max(m2,i);
            i++;
        }

        return max(m1,m2);
    }
};