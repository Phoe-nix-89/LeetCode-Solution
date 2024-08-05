#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1 */

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    unordered_map<int,pair<int,int>> m;
    int mn = INT_MAX;
    int mx = INT_MIN;
    void find(Node* root,int n,int l){
        if(root == NULL) return;
        if(m.find(n) == m.end()){
            m[n] = {root->data,l};
        }
        else{
            if(l>=m[n].second){
                m[n] = {root->data,l};
            }
        }
        
        mn = min(mn,n);
        mx = max(mx,n);
        
        find(root->left,n-1,l+1);
        find(root->right,n+1,l+1);
        
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        find(root,0,0);
        vector<int> ans;
        for(int i=mn;i<=mx;i++){
            ans.push_back(m[i].first);
        }
        
        return ans;
    }
};