#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23 */

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
    vector<int> temp;
    void reval(TreeNode* root,int l){
        if(!root) return;

        if(l == 0) root->val = 0;

        if(l+1<temp.size()){
            int t = temp[l+1];
            if(root->left) t-=root->left->val;
            if(root->right) t-=root->right->val;

            if(root->left) root->left->val = t;
            if(root->right) root->right->val = t;
        }

        reval(root->left,l+1);
        reval(root->right,l+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int sum = 0;
        while(q.size()){
            TreeNode* n = q.front().first;
            int l = q.front().second;
            q.pop();

            if(n->left) q.push({n->left,l+1});
            if(n->right) q.push({n->right,l+1});

            sum += n->val;

            if(q.size() == 0|| l!=q.front().second){
                temp.push_back(sum);
                sum = 0;
            }
        }

        reval(root,0);

        return root;
    }
};