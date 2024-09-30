#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/merge-two-bst-s/1 */

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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> temp;
    vector<int> f;
    vector<int> s;
    void dfs(Node* root){
        if(root == NULL) return;
        
        dfs(root->left);
        temp.push_back(root->data);
        dfs(root->right);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        dfs(root1);
        f = temp;
        temp.clear();
        dfs(root2);
        s = temp;
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i<f.size() || j<s.size()){
            if(i == f.size()){
                ans.push_back(s[j]);
                j++;
            }
            else if(j == s.size()){
                ans.push_back(f[i]);
                i++;
            }
            else if(f[i] <= s[j]){
                ans.push_back(f[i]);
                i++;
            }
            else if(s[j] < f[i]){
                ans.push_back(s[j]);
                j++;
            }
        }
        
        return ans;
    }
};