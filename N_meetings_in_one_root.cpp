#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1 */

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({end[i],start[i]});
        }
        
        sort(temp.begin(),temp.end());
        int i = 0;
        int j = 1;
        int c = 1;
        while(j<temp.size()){
            auto t1 = temp[i];
            auto t2 = temp[j];
            
            if(t2[1] > t1[0]){
                //v.push_back(temp[i]);
                i = j;
                c++;
            }
            j++;
        }
        
        return c;
    }
};