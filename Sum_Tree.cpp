#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/sum-tree/1 */

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    bool c = true;
    int check(Node* root){
        if(root == NULL) return 0;
        
        int l = check(root->left);
        int r = check(root->right);
        
        if((l!=0 && r!=0)){
            if(root->data != (l+r)) c = false;
        }
        else if(l!=0){
            if(root->data != l) c = false;
        }
        else if(r!=0){
            if(root->data != r) c = false;
        }
        
        return (root->data + l + r);
    }
    bool isSumTree(Node* root) {
        // Your code here
        check(root);
        
        return c;
    }
};