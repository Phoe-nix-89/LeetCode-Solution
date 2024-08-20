#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/burning-tree/1 */

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    unordered_map<int,unordered_set<int>> m;
    int t;
    void add(Node* root,Node* r,int target){
        if(root == NULL) return;
        
        if(target == root->data) t = root->data;
        
        if(r != root){
            m[root->data].insert(r->data);
        }
        if(root->left) m[root->data].insert(root->left->data);
        if(root->right) m[root->data].insert(root->right->data);
        
        add(root->left,root,target);
        add(root->right,root,target);
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        add(root,root,target);
        
        
        int c = 0;
        queue<vector<int>> q;
        vector<int> r;
        r.push_back(t);
        q.push(r);
        unordered_set<int> s;
        s.insert(t);
        
        while(q.size()){
            vector<int> temp = q.front();
            q.pop();
            
            vector<int> a;
            
            for(int i : temp){
                for(auto x : m[i]){
                    if(s.find(x) == s.end()){
                        a.push_back(x);
                        s.insert(x);
                        
                    }
                }
            }
            
            if(a.size() > 0){
                q.push(a);
                c++;
            }
            
            
            
        }
        
        return c;
    }
};