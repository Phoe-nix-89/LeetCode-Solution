/*https://leetcode.com/problems/flood-fill/description/*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        queue<pair<int,int>> q;
        unordered_map<int,unordered_set<int>> m;
        q.push({sr,sc});
        m[sr].insert(sc);

        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i-1>=0 && image[i-1][j] == image[i][j] && (m.find(i-1) == m.end() || m[i-1].find(j) == m[i-1].end())){
                q.push({i-1,j});
                m[i-1].insert(j);
            }
            if(i+1<image.size() && image[i+1][j] == image[i][j] && (m.find(i+1) == m.end() || m[i+1].find(j) == m[i+1].end())){
                q.push({i+1,j});
                m[i+1].insert(j);
            }
            if(j-1>=0 && image[i][j-1] == image[i][j] && (m.find(i) == m.end() || m[i].find(j-1) == m[i].end())){
                q.push({i,j-1});
                m[i].insert(j-1);
            }
            if(j+1<image[0].size() && image[i][j+1] == image[i][j] && (m.find(i) == m.end() || m[i].find(j+1) == m[i].end())){
                q.push({i,j+1});
                m[i].insert(j+1);
            }


            image[i][j] = color;
        }


        return image;
    }
};