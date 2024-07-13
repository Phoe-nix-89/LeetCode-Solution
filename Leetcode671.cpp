#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ */

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
    void find(int &m,TreeNode* root){
        if(root == NULL) return;

        m = min(root->val,m);
        find(m,root->left);
        find(m,root->right);
    }
    void find2(int m,TreeNode* root,long long &ans){
        if(root == NULL) return;

        if(root->val != m) {
            if(root->val < ans) ans = root->val;
        }
        find2(m,root->left,ans);
        find2(m,root->right,ans);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int m = INT_MAX;
        find(m,root);
        long long ans = LLONG_MAX;
        find2(m,root,ans);
        if(ans != LLONG_MAX) return ans;
        return -1;
    }
};