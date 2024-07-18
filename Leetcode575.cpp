#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/distribute-candies/ */

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        for(int x : candyType){
            s.insert(x);
        }

        if(s.size() <= (candyType.size()/2)) return s.size();
        return (candyType.size()/2);
    }
};