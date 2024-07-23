#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/minimum-absolute-difference-in-bst/ */

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
    int ans = INT_MAX;
    vector<int> v;
    void find(TreeNode* root){
        if(root == NULL) return;

        find(root->left);
        v.push_back(root->val);
        find(root->right);
        
    }
    int getMinimumDifference(TreeNode* root) {
        find(root);
        int i = 0;
        int j = 1;
        while(j<v.size()){
            ans = min(ans,abs(v[i]-v[j]));
            i++;
            j++;
        }

        return ans;
    }
};