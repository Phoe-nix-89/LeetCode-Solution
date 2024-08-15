#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/lemonade-change/?envType=daily-question&envId=2024-08-15 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0,tn = 0,tw = 0;
        for(int x : bills){
            if(x == 5){
                f++;
            }
            else if(x == 10){
                if(f>0){
                    tn++;
                    f--;
                }
                else return false;
            }
            else if(x == 20){
                if(tn>0 && f>0){
                    tn--;
                    f--;
                    tw++;
                }
                else if(f>=3){
                    tw++;
                    f-=3;
                }
                else return false;
            }
        }

        return true;
    }
};