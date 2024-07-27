#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/merge-two-binary-trees/description/ */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void attach(TreeNode* r1,TreeNode* r,string d){
        if(d == "L"){
            r1->left = r;
        }
        else if(d == "R"){
            r1->right = r;
        }
    }
    void make(TreeNode* r1,TreeNode* r2){
        if(r1 == NULL && r2 == NULL) return;

        r1->val = r1->val + r2->val;

        if(r1->left != NULL && r2->left != NULL){
            make(r1->left,r2->left);
        }
        else if(r1->left == NULL && r2->left != NULL){
            attach(r1,r2->left,"L");
        }

        if(r1->right != NULL && r2->right != NULL){
            make(r1->right,r2->right);
        }
        else if(r1->right == NULL && r2->right != NULL){
            attach(r1,r2->right,"R");
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        else if(root2 == NULL) return root1;
        make(root1,root2);

        return root1;
    }
};