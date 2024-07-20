#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/remove-half-nodes/1 */

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// the code :-
class Solution {
  public:
    Node* make(Node* root){
        if(root == NULL) return NULL;
        
        Node* l = make(root->left);
        Node* r = make(root->right);
        
        if(l!=NULL && ((l->left != NULL && l->right == NULL) || (l->left == NULL && l->right != NULL)) ){
            if(l->left){
                root->left = l->left;
            }
            else if(l->right){
                root->left = l->right;
            }
        }
        if(r!=NULL && ((r->left != NULL && r->right == NULL) || (r->left == NULL && r->right != NULL)) ){
            if(r->left){
                root->right = r->left;
            }
            else if(r->right){
                root->right = r->right;
            }
        }
        
        
        return root;
    }
    Node *RemoveHalfNodes(Node *root) {
        // code here
        make(root);
        
        if(root->left != NULL && root->right == NULL) return root->left;
        if(root->left == NULL && root->right != NULL) return root->right;
        return root;
    }
};