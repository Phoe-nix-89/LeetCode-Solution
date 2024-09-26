#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/my-calendar-i/?envType=daily-question&envId=2024-09-26 */

class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.size() == 0) {
            v.push_back({start,end});
            return true;
        }
        bool flag = true;
        for(auto x : v){
            if((start>=x[0] && start<x[1]) || (end>x[0] && end<=x[1]) || (x[0]>=start && x[0]<end) || (x[1]>start && x[1]<=end) ){
                flag = false;
                break;
            }
        }
        if(flag){
            v.push_back({start,end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */