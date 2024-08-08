#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08 */

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int x1 = rStart;
        int x2 = rStart;
        int y1 = cStart;
        int y2 = cStart;
        int a1 = rStart;
        int a2 = cStart;
        int c = 0;
        int t = rows*cols;
        vector<vector<int>> ans;
        while(c < t){
            x1 -= 1;
            x2 += 1;
            y1 -= 1;
            y2 += 1;

            while(a2<y2){
                if(c == t) break;
                if(a1>=0 && a1<rows && a2>=0 && a2<cols){
                    ans.push_back({a1,a2});
                    c++;
                }
                a2++;
            }
            if(c == t) break;
            while(a1<x2){
                if(c == t) break;
                if(a1>=0 && a1<rows && a2>=0 && a2<cols){
                    ans.push_back({a1,a2});
                    c++;
                }
                a1++;
            }
            if(c == t) break;
            while(a2>y1){
                if(c == t) break;
                if(a1>=0 && a1<rows && a2>=0 && a2<cols){
                    ans.push_back({a1,a2});
                    c++;
                }
                a2--;
            }
            if(c == t) break;
            while(a1>x1){
                if(c == t) break;
                if(a1>=0 && a1<rows && a2>=0 && a2<cols){
                    ans.push_back({a1,a2});
                    c++;
                }
                a1--;
            }
            if(c == t) break;
            while(a2<y2){
                if(c == t) break;
                if(a1>=0 && a1<rows && a2>=0 && a2<cols){
                    ans.push_back({a1,a2});
                    c++;
                }
                a2++;
            }
            if(c == t) break;

            
        }

        return ans;
    }
};