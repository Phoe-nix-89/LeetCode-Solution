#include<bits/stdc++.h>
using namespace std;

/**/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ce = 0;
        int count = 0;
        while(numBottles > 0){
            numBottles--;

            count++;
            ce++;
            if(ce == numExchange){
                ce = 0;
                numBottles += 1;
            }
        }

        return count;
    }
};