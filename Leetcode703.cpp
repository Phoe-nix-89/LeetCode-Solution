#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/kth-largest-element-in-a-stream/?envType=daily-question&envId=2024-08-12 */

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    int t;
    KthLargest(int k, vector<int>& nums) {
        t = k;
        for(int x : nums){
            if(p.size() < k) p.push(x);
            else if(x > p.top()){
                p.push(x);
                p.pop();
            }
        }
    }
    
    int add(int val) {
        if(p.size() < t){
            p.push(val);
        }
        else if(val > p.top()){
            p.pop();
            p.push(val);
        }

        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */