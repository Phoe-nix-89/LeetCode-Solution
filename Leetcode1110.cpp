#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17 */

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
    unordered_set<int> s;
    unordered_set<TreeNode*> ans;
    TreeNode* r;
    void find(TreeNode* root,TreeNode* p){
        if(root == NULL) return;

        find(root->left,root);
        find(root->right,root);

        if(s.find(root->val) != s.end()){
            ans.erase(root);
            if(root->left){
                ans.insert(root->left);
            }
            if(root->right){
                ans.insert(root->right);
            }

            if(root != r){
                if(p->left == root){
                    p->left = NULL;
                }
                else if(p->right == root){
                    p->right = NULL;
                }
            }

            return;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int x : to_delete){
            s.insert(x);
        }
        ans.insert(root);
        r = root;
        find(root,root);

        vector<TreeNode*> v;
        for(auto x : ans){
            v.push_back(x);
        }

        return v;
    }
};