#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=daily-question&envId=2024-07-08 */

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);

        int c = 1;
        while(q.size() > 1){
            if(c == k){
                c = 1;
                q.pop();
            }
            else{
                int temp = q.front();
                q.pop();
                q.push(temp);
                c++;
            }
        }

        return q.front();
    }
};