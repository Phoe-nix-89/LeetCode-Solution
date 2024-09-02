#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02 */

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int x : chalk) sum += x;

        long long temp = k % sum;
        if(temp == 0) return 0;
        for(int i=0;i<chalk.size();i++){
            if(temp < chalk[i]) return i;
            else temp -= chalk[i];
        }

        return -1;
    }
};