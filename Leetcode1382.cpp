/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* /*https://leetcode.com/problems/balance-a-binary-search-tree/description/  */
#include<bits/stdc++.h>
using namespace std;

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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* make(int i,int j){
        if(i>j) return NULL;



        int m = i + (j-i)/2;
        TreeNode* temp = new TreeNode(v[m]);

        temp->left = make(i,m-1);
        temp->right = make(m+1,j);

        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return root;
        inorder(root);
        int i = 0;
        int j = v.size()-1;
        return make(i,j);
    }
};