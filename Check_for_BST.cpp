#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    vector<int> temp;
    void find(Node* root){
        if(root == NULL) return;
        
        find(root->left);
        temp.push_back(root->data);
        find(root->right);
    }
    bool isBST(Node* root) {
        // Your code here
        
        find(root);
        
        for(int i=1;i<temp.size();i++){
            if(temp[i-1] >= temp[i]) return false;
        }
        
        return true;
    }
};